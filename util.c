/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:50:33 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 10:54:04 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	error_exit(char *msg)
{
	if (msg != NULL)
	{
		ft_putstr_fd("Error!\n", 2);
		ft_putstr_fd(msg, 2);
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

void	*ft_malloc_err(size_t size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)malloc(size);
	if (ptr == NULL)
		error_exit("Malloc failed.");
	return ((void *)ptr);
}
