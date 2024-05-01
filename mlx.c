/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumilee <sumilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:29:54 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/01 19:34:13 by sumilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type.h"
#include "util.h"


int	key_hook(int key, t_mlxdata *data)
{
	if (key == KEY_ESC)
		win_close(&data->ptr);
	else if (key == KEY_W)
	{

	}
	else if (key == KEY_A)
	{

	}
	else if (key == KEY_S)
	{

	}
	else if (key == KEY_D)
	{

	}
	return (0);
}