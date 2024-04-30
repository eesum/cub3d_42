/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/30 17:24:52 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ray.h"
#include "type.h"

int	main(int argc, char **argv)
{
	t_mlxdata	mlxdata;
	t_player	player;
	char		**map;

	map = NULL;
	parsing(argc, argv, &mlxdata.info, &map);
	init_player_info(map, &player);
	init_mlx_data(&mlxdata, &argv[0][2]);
	while (1)
	{
		ray_loop(map, &mlxdata, &player);
	}
	return (0);
}
