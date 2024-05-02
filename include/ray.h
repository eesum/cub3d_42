/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:00 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 21:20:36 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "type.h"

void	ray_loop(char **map, t_mlxdata *mlxdata, t_player *player);

void	init_screen(t_render *render, t_mlxdata *mlxdata);
void	draw_line(int line, t_mlxdata *mlxdata, t_ray *ray, t_render *render);

#endif