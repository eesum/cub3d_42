/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:22:28 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 21:25:40 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"
#include "mlx.h"

static char	init_player_info_loop(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_palyer_pos(map[i][j]))
			{
				player->pos_x = j + 0.5;
				player->pos_y = i + 0.5;
				return (map[i][j]);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_player_info(char **map, t_player *player)
{
	char c;

	ft_memset(player, 0, sizeof(int) * 6);
	c = init_player_info_loop(map, player);
	if (c == 'N')
	{
		player->dir_y = -1;
		player->plane_x = PLANE;
	}
	else if (c == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -1 * PLANE;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->plane_y = PLANE;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -1 * PLANE;
	}
}

static void	info_to_img(t_ptr *ptr, t_map_info *info, t_img *img)
{
	img->img_h = IMG_H;
	img->img_w = IMG_W;
	img->img[WALL_NO] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->north, \
									&img->img_w, &img->img_h);
	img->img[WALL_SO] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->south, \
									&img->img_w, &img->img_h);
	img->img[WALL_WE] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->west, \
									&img->img_w, &img->img_h);
	img->img[WALL_EA] = mlx_xpm_file_to_image(ptr->mlx_ptr, info->east, \
									&img->img_w, &img->img_h);
	if (img->img[0] == NULL || img->img[1] == NULL || \
		img->img[2] == NULL || img->img[3] == NULL)
		error_exit("Graphic image error.");
}

void	init_mlx_data(t_mlxdata *mlxdata, char *program_name)
{
	mlxdata->ptr.mlx_ptr = mlx_init();
	if (mlxdata->ptr.mlx_ptr == NULL)
		error_exit("Mlx init failed.");
	mlxdata->ptr.win_ptr = mlx_new_window(mlxdata->ptr.mlx_ptr, \
									WIN_W, WIN_H, program_name);
	if (mlxdata->ptr.win_ptr == NULL)
		error_exit("New mlx window creation failed.");
	info_to_img(&mlxdata->ptr, &mlxdata->info, &mlxdata->img);
	ft_memset(mlxdata->key_flag, 0, sizeof(int) * 6);
}
