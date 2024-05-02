/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:11:20 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 14:13:30 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# define PLANE 10
# define IMG_H 32 //추후 다른 헤더로 이동 가능
# define IMG_W 32
# define WIN_W 1984
# define WIN_H 1024
# define WALL_NO 0
# define WALL_SO 1
# define WALL_WE 2
# define WALL_EA 3
# define BUTTON_DESTROY 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LE 123
# define KEY_RI 124

typedef struct s_ptr	//추후 다른 헤더로 이동 가능
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptr;

typedef struct s_render
{
	void 	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
}				t_render;

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
	void	*img[4];
	// void	*no_img;
	// void	*so_img;
	// void	*we_img;
	// void	*ea_img;
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
	double	step_x; //what direction to step
	double	step_y;
	double	side_x; //current position to next x or y-side
	double	side_y;
	double	delta_x; //one x or y-side to next x or y-side
	double	delta_y;
	int		hit; //벽에 맞았는지
	int		hit_side; //어느쪽 벽에 맞았는지
	double	walldist; //카메라평면에 수직으로 그은 거리
	int		wall_type;
	double	texture_x;
	int		height;
	int		draw_start;
	int		draw_end;
}				t_ray;

#endif