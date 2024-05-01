/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:31:26 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 03:22:00 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ray.h"
#include "mlx.h"
#include "util.h"
#include "parse.h"
#include <math.h>
#include <stdlib.h>


#include <stdio.h>//

void	init_step(t_ray *ray, t_player *player)
{
	ray->map_x = (int)(player->pos_x); //double을 int로 캐스팅하면 어떻게 되지?
	ray->map_y = (int)(player->pos_y);
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
	ray->hit = 0;
	if (ray->raydir_x >= 0)
	{
		ray->step_x = 1;
		ray->side_x = (player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
	 	ray->step_x = -1;
		ray->side_x = (ray->map_x + 1 - player->pos_x) * ray->delta_x;
	}
	if (ray->raydir_y >= 0)
	{
		ray->step_y = 1;
		ray->side_y = (player->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = -1;
		ray->side_y = (ray->map_y + 1 - player->pos_y) * ray->delta_y;
	}
}

void	cal_dda(char **map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->hit_side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	// printf("hit! x: %d, y: %d\n", ray->map_x, ray->map_y);
}

void	cal_walldist(t_ray *ray, t_player *player)
{
	double	diff;

	if (ray->hit_side == 0)
	{
		diff = ray->map_x - player->pos_x + (1 - ray->step_x) / 2;
		ray->walldist = diff / ray->raydir_x;
	}
	else
	{
		diff = ray->map_y - player->pos_y + (1 - ray->step_y) / 2;
		ray->walldist = diff / ray->raydir_y;
	}
	// printf("dist: %f\n", ray->walldist);
}

void	cal_wallx(t_ray *ray, t_player *player)
{
	double	wall_x;

	if (ray->hit_side == 0)
		wall_x = player->pos_y + ray->walldist * ray->raydir_y;
	else
		wall_x = player->pos_x + ray->walldist * ray->raydir_x;
	wall_x -= floor(wall_x);
	ray->texture_x = (int) (wall_x * (double) IMG_W);
	if (ray->raydir_y > 0 && ray->hit_side == 1)
		ray->wall_type = WALL_NO;
	if (ray->raydir_y < 0 && ray->hit_side == 1)
	{
		ray->wall_type = WALL_SO;
		ray->texture_x = IMG_W - 1 - ray->texture_x;
	}
	if (ray->raydir_x < 0 && ray->hit_side == 0)
		ray->wall_type = WALL_WE;
	if (ray->raydir_x > 0 && ray->hit_side == 0)
	{
		ray->wall_type = WALL_EA;
		ray->texture_x = IMG_W - 1 - ray->texture_x;
	}
}

void	cal_wallheight(t_ray *ray)
{
	ray->height = (int) WIN_H / ray->walldist;
	ray->draw_start = WIN_H / 2 - ray->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = WIN_H / 2 + ray->height / 2;
	if (ray->draw_end > WIN_H)
		ray->draw_end = WIN_H - 1;

	// printf("height: %d, start: %d, end: %d\n", ray->height, ray->draw_start, ray->draw_end);
}

int	get_color_from_texture(t_mlxdata *data, t_ray *ray, int x, int y)
{
	int	color;
	int	*addr;
	t_render	texture;

	texture.addr = mlx_get_data_addr(data->img.img[ray->wall_type], &texture.bits_per_pixel, &texture.size_line, &texture.endian);
	if (texture.addr == NULL)
		error_exit("Mlx error.");
	addr = (int *)texture.addr;
	if (ray->height > WIN_H)
		y += (ray->height - WIN_H) / 2;
	else
		y -= (WIN_H - ray->height) / 2;
	y *= IMG_H / ray->height;
	color = *(addr + y * IMG_W + x);
	return (color);
}

void	draw_line(int line, t_mlxdata *mlxdata, t_ray *ray, t_render *render)
{
	int	color;
	int i;
	char	*pixel;

	i = 0;

	while (i < WIN_H)
	{
		pixel = render->addr + (i * render->size_line) + (line * render->bits_per_pixel / 8);
		if (i < ray->draw_start || i > ray->draw_end)
			*(int *)pixel = 0xFFFFFFFF;
		else
		{
			color = get_color_from_texture(mlxdata, ray, (int)ray->texture_x, i);
			*(int *)pixel = color;
		}
		i++;
	}
}



void	ray_loop(char **map, t_mlxdata *mlxdata, t_player *player)
{
	t_ray	ray;
	t_render	render;
	int	i;
	double cam_x; //배수

	i = 0;
	render.img = mlx_new_image(mlxdata->ptr.mlx_ptr, WIN_W, WIN_H);
	if (render.img == NULL)
		error_exit("Mlx error.");
	render.addr = mlx_get_data_addr(render.img, &render.bits_per_pixel, &render.size_line, &render.endian);
	if (render.addr == NULL)
		error_exit("Mlx error.");
	while (i < WIN_W)
	{
		cam_x = 2 * i / (double)WIN_W - 1;
		ray.raydir_x = player->dir_x + player->plane_x * cam_x;
		ray.raydir_y = player->dir_y + player->plane_y * cam_x;
		// printf("cam: %f, rayx: %f, rayy: %f\n", cam_x, ray.raydir_x, ray.raydir_y);
		init_step(&ray, player);
		cal_dda(map, &ray);
		cal_walldist(&ray, player);
		cal_wallx(&ray, player);
		cal_wallheight(&ray);
		draw_line(i, mlxdata, &ray, &render);
		i++;
	}
	put_image(&mlxdata->ptr, render.img, 0, 0);


}

	// printf("hi map_y: %d, map_x: %d, map: %c\n", ray->map_y, ray->map_x, map[ray->map_y][ray->map_x]);
