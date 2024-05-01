/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:47:36 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/01 19:15:38 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

void	parsing(int argc, char **argv, t_map_info *info, char ***map)
{
	int len;
	int fd;

	if (argc != 2)
		error_exit("Wrong number of argument(s).");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_memcmp(".cub", &argv[1][len - 4], 5) != 0)
		error_exit("Wrong map file type.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("Can't open file.");
	parse_map_info(fd, info);
	parse_map(fd, map);
}

static void	init_info(t_map_info *info)
{
	info->north = NULL;
	info->south = NULL;
	info->east = NULL;
	info->west = NULL;
	info->floor = NULL;
	info->ceiling = NULL;
}

static int	find_n_save(char **split, t_map_info *info, int *cnt)
{
	if (!info->north && ft_memcmp("NO", split[0], 3) == 0 && !split[2])
		info->north = ft_strdup_err(split[1]);
	else if (!info->south && ft_memcmp("SO", split[0], 3) == 0 && !split[2])
		info->south = ft_strdup_err(split[1]);
	else if (!info->west && ft_memcmp("WE", split[0], 3) == 0 && !split[2])
		info->west = ft_strdup_err(split[1]);
	else if (!info->east && ft_memcmp("EA", split[0], 3) == 0 && !split[2])
		info->east = ft_strdup_err(split[1]);
	else if (!info->floor && ft_memcmp("F", split[0], 2) == 0 && !split[2])
		info->floor = ft_strdup_err(split[1]);
	else if (!info->ceiling && ft_memcmp("C", split[0], 2) == 0 && !split[2])
		info->ceiling = ft_strdup_err(split[1]);
	else
	{
		free_arr(split);
		return (1);
	}
	(*cnt)++;
	free_arr(split);
	return (0);
}

static void	count_comma(char *code)
{
	int	i;
	int cnt;

	i = 0;
	cnt = 0;
	while (code[i])
	{
		if (code[i] == ',')
			cnt++;
		i++;
	}
	if (cnt != 2)
		error_exit("Wrong color information.");
}

static void	convert_color(char *code, int *color)
{
	char **split;
	int temp;
	int result;
	int	i;

	count_comma(code);
	split = ft_split(code, ',');
	if (split == NULL) 
		error_exit("Malloc failed.");
	if (split[0] == NULL)
		error_exit("Wrong color information.");
	i = 0;
	result = 0;
	while (i < 3 && split[i])
	{
		temp = ft_atoi_err(split[i]);
		if (temp > 255)
			error_exit("Wrong color information.");
		result |= temp << ((2 - i) * 8);
		i++;
	}
	if (i != 3 || split[i] != NULL)
		error_exit("Wrong color information.");
	*color = result;
	free_arr(split);
}

void	parse_map_info(int fd, t_map_info *info)
{
	char *buff;
	char **split;
	int	cnt;

	init_info(info);
	cnt = 0;
	while (cnt < 6)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		buff[ft_strlen(buff) - 1] = '\0';
		split = ft_split(buff, ' ');
		if (split == NULL)
			error_exit("Malloc failed.");
		free(buff);
		if (split[0] != NULL && find_n_save(split, info, &cnt) > 0)
			break ;
	}
	if (cnt != 6)
		error_exit("Wrong graphic information.");
	convert_color(info->floor, &info->fl_color);
	convert_color(info->ceiling, &info->cl_color);
}
