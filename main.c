/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/26 23:53:55 by seohyeki         ###   ########.fr       */
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

	if (argc != 2)
		error_exit("args.");
	map = NULL;
	fd = check_argv(argc, argv);
	parse_map_info(fd, &info);
	parse_map(fd, &map);
	init_mlx_data(&ptr, &info, &img, &argv[0][2]); // map 파싱까지 하고 mlx 들아가도 될듯. 순서 추후 고민
	return (0);
}
