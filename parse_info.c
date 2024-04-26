/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:47:36 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 15:48:25 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"
#include <fcntl.h>

int	check_argv(int argc, char **argv)
{
	int len;
	int fd;

	if (argc != 2)
		error_exit("Wrong number of argument(s).");
	len = ft_strlen(argv[1]);
	if (len < 5 || ft_memcmp(".cub", &argv[1][len - 4], 5) != 0)
		error_exit("Wrong map type.");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_exit("Can't open file.");
	return (fd);
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
	if (!info->north && ft_memcmp("NO", split[0], 3) == 0)
		info->north = ft_strdup_err(split[1]);
	else if (!info->south && ft_memcmp("SO", split[0], 3) == 0)
		info->south = ft_strdup_err(split[1]);
	else if (!info->west && ft_memcmp("WE", split[0], 3) == 0)
		info->west = ft_strdup_err(split[1]);
	else if (!info->east && ft_memcmp("EA", split[0], 3) == 0)
		info->east = ft_strdup_err(split[1]);
	else if (!info->floor && ft_memcmp("F", split[0], 2) == 0)
		info->floor = ft_strdup_err(split[1]);
	else if (!info->ceiling && ft_memcmp("C", split[0], 2) == 0)
		info->ceiling = ft_strdup_err(split[1]);
	else
	{
		free_all(split);
		return (1);
	}
	(*cnt)++;
	free_all(split);
	return (0);
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
		split = ft_split(buff, ' ');
		if (split == NULL)
			error_exit("Malloc failed.");
		free(buff);
		if (split[0] != NULL && find_n_save(split, info, &cnt) < 0)
			break ;
	}
	if (cnt != 6)
		error_exit("Wrong map information.");
}
