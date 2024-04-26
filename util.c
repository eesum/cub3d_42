/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:50:33 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 19:39:16 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/util.h"

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

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
