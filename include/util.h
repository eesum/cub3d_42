/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:51:05 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/01 19:34:30 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "libft.h"
# include "type.h"

void	*ft_malloc_err(size_t size);
char	*ft_strdup_err(const char *s1);
int		ft_atoi_err(const char *nptr);
void	error_exit(char *msg);
void	free_arr(char **arr);
int		win_close(t_ptr *ptr);
int		key_hook(int key, t_mlxdata *data);

#endif