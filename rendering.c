/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 21:16:19 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 22:22:31 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "util.h"
#include "mlx.h"

void	init_screen(t_render *screen, t_ptr *ptr)
{
	screen->img = mlx_new_image(ptr->mlx_ptr, WIN_W, WIN_H);
	if (screen->img == NULL)
		error_exit("Mlx error.");
	screen->addr = mlx_get_data_addr(screen->img, \
									&screen->bits_per_pixel, \
									&screen->size_line, \
									&screen->endian);
	if (screen->addr == NULL)
		error_exit("Mlx error.");
}

static int	get_color_from_texture(void **img, t_ray *ray, int x, int y)
{
	int	color;
	int	*addr;
	t_render	texture;

	texture.addr = mlx_get_data_addr(img[ray->wall_type], &texture.bits_per_pixel, &texture.size_line, &texture.endian);
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

void	draw_line(int line, t_img *img, t_ray *ray, t_render *screen)
{
	int	color;
	int i;
	char	*pixel;

	i = 0;
	while (i < WIN_H)
	{
		pixel = screen->addr + (i * screen->size_line) + (line * screen->bits_per_pixel / 8);
		if (i < ray->draw_start)
			*(int *)pixel = img->cl_color;
		else if (i > ray->draw_end)
			*(int *)pixel = img->fl_color;
		else
		{
			color = get_color_from_texture(img->texture, ray, (int)ray->texture_x, i);
			*(int *)pixel = color;
		}
		i++;
	}
}
