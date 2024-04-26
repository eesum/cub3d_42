/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:34 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 16:49:46 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H


# define IMG_H 32 //추후 다른 헤더로 이동 가능
# define IMG_W 32

# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_ptr	//추후 다른 헤더로 이동 가능
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptr;

typedef struct s_map_info
{
	char *north;
	char *south;
	char *west;
	char *east;
	char *floor;
	char *ceiling;
	int fl_color;
	int cl_color;
}				t_map_info;

typedef struct s_img
{
	int	img_h;
	int	img_w;
	void *no_img;
	void *so_img;
	void *we_img;
	void *ea_img;
	void *fl_img;
	void *cl_img;
}				t_img;

int		check_argv(int argc, char **argv);
void	parse_map_info(int fd, t_map_info *info);


#endif