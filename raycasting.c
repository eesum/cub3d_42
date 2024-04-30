/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:31:26 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/30 18:30:01 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "ray.h"
#include <math.h>

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

void	cal_dda(char **map, t_ray *ray, t_player *player)
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
		if (map[ray->map_y][ray->map_x] == 1)
			ray->hit = 1;
	}
}

void	cal_walldist(t_ray *ray)
{
	double	diff;

	if (ray->hit_side)
	{
		ray->walldist;
		
	}
}

void	ray_loop(char **map, t_mlxdata *mlxdata, t_player *player)
{
	t_ray	ray;
	int	i;
	double cam_x; //배수

	i = 0;
	while (i < WIN_W)
	{
		cam_x = 2 * i / (double)cam_x - 1;
		ray.raydir_x = player->dir_x + player->plane_x * cam_x;
		ray.raydir_y = player->dir_y + player->plane_y * cam_x;
		init_step(&ray, player);
		cal_dda(map, &ray, player);
		cal_walldist(&ray);
		cal_hight
		i++;
	}



}