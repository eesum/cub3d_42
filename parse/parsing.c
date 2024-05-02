/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:27:17 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 21:38:21 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "type.h"
#include "util.h"
#include <fcntl.h>

void	parsing(int argc, char **argv, t_mlxdata *mlxdata)
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
	parse_map_info(fd, &mlxdata->info);
	parse_map(fd, &mlxdata->map);
	init_player_info(mlxdata->map, &mlxdata->player);
	init_mlx_data(mlxdata, &argv[0][2]);
}
