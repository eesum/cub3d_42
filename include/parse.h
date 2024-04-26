/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:34:34 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 11:08:35 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "libft.h"
# include <unistd.h>

typedef struct s_map_info
{
	char *north;
	char *south;
	char *west;
	char *east;
	char *floor;
	char *ceiling;
}				t_map_info;

typedef struct s_img
{
	void *no_img;
	void *so_img;
	void *we_img;
	void *ea_img;
	void *fl_img;
	void *cl_img;
}				t_img;

#endif