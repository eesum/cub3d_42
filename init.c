/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:22:28 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 20:21:34 by sumilee          ###   ########.fr       */
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
	void 	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;

	img = mlx_new_image(ptr, IMG_W, IMG_H);
	if (img == NULL)
		return (NULL);
	addr = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);
	if (addr == NULL)
		return (NULL);
	put_color(addr, bits_per_pixel / 8, size_line, color);
	return (img);
}

static void	info_to_img(t_ptr *ptr, t_map_info *info, t_img *img)
{
	img->img_h = IMG_H;
	img->img_w = IMG_W;
	img->no_img = mlx_xpm_file_to_image(ptr->mlx_ptr, info->north, \
									&img->img_w, &img->img_h);
	img->so_img = mlx_xpm_file_to_image(ptr->mlx_ptr, info->south, \
									&img->img_w, &img->img_h);
	img->we_img = mlx_xpm_file_to_image(ptr->mlx_ptr, info->west, \
									&img->img_w, &img->img_h);
	img->ea_img = mlx_xpm_file_to_image(ptr->mlx_ptr, info->east, \
									&img->img_w, &img->img_h);
	img->fl_img = color_to_img(ptr, info->fl_color);
	img->cl_img = color_to_img(ptr, info->cl_color);
	if (img->no_img == NULL || img->so_img == NULL || img->we_img == NULL || \
		img->ea_img == NULL || img->fl_img == NULL || img->cl_img == NULL)
		error_exit("Graphic image error.");
}

void	put_image(t_ptr *ptr, void *img, int x, int y) // 나중에 유틸이나 다른곳으로 옮겨야할듯. 일단 테스트용
{
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, \
							img, y * IMG_W, x * IMG_H);
}

void	init_mlx_data(t_ptr *ptr, t_map_info *info, t_img *img, char *program_name)
{
	ptr->mlx_ptr = mlx_init();
	if (ptr->mlx_ptr == NULL)
		error_exit("Mlx init failed.");
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, \
									6 * IMG_W, \
									1 * IMG_H, program_name);
	if (ptr->win_ptr == NULL)
		error_exit("New mlx window creation failed.");
	info_to_img(ptr, info, img);
	
	/* 아래는 테스트 용 */
	put_image(ptr, img->no_img, 0, 0);
	put_image(ptr, img->so_img, 0, 1);
	put_image(ptr, img->we_img, 0, 2);
	put_image(ptr, img->ea_img, 0, 3);
	put_image(ptr, img->fl_img, 0, 4);
	put_image(ptr, img->cl_img, 0, 5);
	mlx_loop(ptr->mlx_ptr);
}