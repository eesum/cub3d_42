/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:51:05 by sumilee           #+#    #+#             */
/*   Updated: 2024/04/26 23:51:57 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../libft/libft.h"
# include <stdlib.h>

void	error_exit(char *msg);
void	*ft_malloc_err(size_t size);
char	*ft_strdup_err(const char *s1);
int		ft_atoi_err(const char *nptr);
void	free_all(char **arg);
void	free_arr(char **arr);

#endif