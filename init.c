/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:22:28 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 19:50:59 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static void	put_color(char *addr, int bytes_per_pixel, int size_line, int color)
{
	int i;
	int	j;
	char	*pixel;

	i = 0;
	while (i < IMG_W)
	{
		j = 0;
		while (j < IMG_H)
		{
			pixel = addr + (j * size_line) + (i * bytes_per_pixel);
			*(int *)pixel = color;
			j++;
		}
		i++;
	}
}

static void	*color_to_img(void *ptr, int color)
{
	t_render render;

	render.img = mlx_new_image(ptr, IMG_W, IMG_H);
	if (render.img == NULL)
		return (NULL);
	render.addr = mlx_get_data_addr(render.img, &render.bits_per_pixel, &render.size_line, &render.endian);
	if (render.addr == NULL)
		return (NULL);
	put_color(render.addr, render.bits_per_pixel / 8, render.size_line, color);
	return (render.img);
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
	img->fl_img = color_to_img(ptr, info->fl_color);
	img->cl_img = color_to_img(ptr, info->cl_color);
	if (img->img[0] == NULL || img->img[1] == NULL || img->img[2] == NULL || \
		img->img[3] == NULL || img->fl_img == NULL || img->cl_img == NULL)
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

char	init_player_info_loop(char **map, t_player *player)
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