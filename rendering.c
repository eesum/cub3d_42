/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:16:19 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 21:18:02 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "type.h"
#include "util.h"
#include "mlx.h"

void	init_screen(t_render *render, t_mlxdata *mlxdata)
{
	render->img = mlx_new_image(mlxdata->ptr.mlx_ptr, WIN_W, WIN_H);
	if (render->img == NULL)
		error_exit("Mlx error.");
	render->addr = mlx_get_data_addr(render->img, \
									&render->bits_per_pixel, \
									&render->size_line, \
									&render->endian);
	if (render->addr == NULL)
		error_exit("Mlx error.");
}

static int	get_color_from_texture(t_mlxdata *data, t_ray *ray, int x, int y)
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
	y = y * (IMG_H - 1) / ray->height;
	color = *(addr + y * texture.size_line / 4 + x);
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
		if (i < ray->draw_start)
			*(int *)pixel = mlxdata->info.cl_color;
		else if (i > ray->draw_end)
			*(int *)pixel = mlxdata->info.fl_color;
		else
		{
			color = get_color_from_texture(mlxdata, ray, (int)ray->texture_x, i);
			*(int *)pixel = color;
		}
		i++;
	}
}
