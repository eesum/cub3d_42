/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/29 19:57:52 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

int	main(int argc, char **argv)
{
	t_ptr		ptr;
	t_img		img;
	t_map_info	info;
	int			fd;
	char		**map;

	map = NULL;
	fd = check_argv(argc, argv);
	parse_map_info(fd, &info);
	parse_map(fd, &map);
	init_mlx_data(&ptr, &info, &img, &argv[0][2]);
	return (0);
}
