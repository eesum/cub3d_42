/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:34 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/30 17:21:33 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include "type.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

void	parsing(int argc, char **argv, t_map_info *info, char ***map);

/*parse_map*/
void	parse_map_info(int fd, t_map_info *info);

/*parse_map*/
void	parse_map(int fd, char ***map);
void	ft_lst_trim(t_list **map);
void	check_map_valid(t_list *map);
void	check_surrounded_wall(char **map, size_t col, size_t row);

/*parse_map utils*/
int		is_emptyline(char *str);
int		is_palyer_pos(char c);
int		is_not_element(char *str, int *player_flag);

/*init data*/
void	init_player_info(char **map, t_player *player);
void	init_mlx_data(t_mlxdata *mlxdata, char *program_name);	//추후 다른 헤더로 이동 가능

#endif