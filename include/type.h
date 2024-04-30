/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:11:20 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/30 18:02:35 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define IMG_H 32 //추후 다른 헤더로 이동 가능
# define IMG_W 32
# define WIN_W 2000
# define WIN_H 1000

typedef struct s_ptr	//추후 다른 헤더로 이동 가능
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptr;

typedef struct s_map_info
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
	int		fl_color;
	int		cl_color;
}				t_map_info;

typedef struct s_img
{
	int		img_h;
	int		img_w;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	void	*fl_img;
	void	*cl_img;
}				t_img;

typedef struct s_mlxdata
{
	t_ptr	ptr;
	t_img	img;
	t_map_info	info;
}				t_mlxdata;

typedef struct s_player
{
	double	pos_x; //player start pos
	double	pos_y;
	double	dir_x; //player 초기 방향
	double	dir_y;
	double	plane_x; //camera plane
	double	plane_y;
}				t_player;

typedef struct s_ray
{
	int		map_x; //pos_x, pos_y 정수값
	int		map_y;
	double	raydir_x; //광선의 방향벡터
	double	raydir_y;
	double	side_x; //current position to next x or y-side
	double	side_y;
	double	delta_x; //one x or y-side to next x or y-side
	double	delta_y;
	double	walldist; //카메라평면에 수직으로 그은 거리
	double	step_x; //what direction to step
	double	step_y;
	int		hit; //벽에 맞았는지
	int		hit_side; //어느쪽 벽에 맞았는지
}				t_ray;

#endif