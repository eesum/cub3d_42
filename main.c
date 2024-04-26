/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:35:44 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 20:20:51 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


int main(int argc, char **argv)
{
	t_ptr	ptr;
	t_img	img;
	t_map_info	info;
	int fd;
	
	fd = check_argv(argc, argv);
	parse_map_info(fd, &info);
	init_mlx_data(&ptr, &info, &img, &argv[0][2]); // map 파싱까지 하고 mlx 들아가도 될듯. 순서 추후 고민
	
	return (0);
}