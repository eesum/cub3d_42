/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:51:05 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/29 20:01:24 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "libft.h"

void	*ft_malloc_err(size_t size);
char	*ft_strdup_err(const char *s1);
int		ft_atoi_err(const char *nptr);
void	error_exit(char *msg);
void	free_arr(char **arr);

#endif