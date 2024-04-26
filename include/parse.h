/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:34 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 19:38:18 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft/libft.h"

typedef struct s_map_info
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}				t_map_info;

typedef struct s_img
{
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	void	*fl_img;
	void	*cl_img;
}				t_img;

/*parse_map*/
void	parse_map(int fd, char ***map);
void	lst_trim(t_list **map);
void	check_map_valid(t_list *map);
void	check_surrounded_wall(char **map, size_t col, size_t row);

/*parse_map utils*/
int		is_emptyline(char *str);
int		is_palyer_pos(char c);
int		is_not_element(char *str, int *player_flag);
#endif