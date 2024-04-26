/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:35:44 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 15:51:04 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


int main(int argc, char **argv)
{
	// t_ptr	ptr;
	// t_img	img;
	t_map_info	info;
	int fd;
	
	// ptr.mlx_ptr = mlx_init();
	// if (ptr.mlx_ptr == NULL)
	// 	error_exit("Mlx init failed.");
	fd = check_argv(argc, argv);
	parse_map_info(fd, &info);
	
	return (0);
}