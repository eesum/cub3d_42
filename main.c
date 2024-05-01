/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/05/02 01:51:11 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "ray.h"
#include "type.h"
#include "util.h"

int	main(int argc, char **argv)
{
	t_mlxdata	mlxdata;
	t_player	player;
	char		**map;

	map = NULL;
	parsing(argc, argv, &mlxdata.info, &map);
	init_player_info(map, &player);
	init_mlx_data(&mlxdata, &argv[0][2]);
	ray_loop(map, &mlxdata, &player);
	mlx_hook(mlxdata.ptr.win_ptr, 17, 0, win_close, &mlxdata.ptr);
	mlx_key_hook(mlxdata.ptr.win_ptr, key_hook, &mlxdata);
	mlx_loop(mlxdata.ptr.mlx_ptr);

	//전체 free
	return (0);
}
