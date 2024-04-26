/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:05:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/26 19:44:05 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parse.h"
#include "include/util.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	if (argc != 2)
		error_exit("args.");
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	parse_map(fd, &map);
}
