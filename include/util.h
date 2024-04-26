/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:51:05 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 16:38:09 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

void	error_exit(char *msg);
void	*ft_malloc_err(size_t size);
char	*ft_strdup_err(const char *s1);
int		ft_atoi_err(const char *nptr);
void	free_all(char **arg);

#endif