/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:29:54 by sumilee           #+#    #+#             */
/*   Updated: 2024/05/02 18:01:55 by seohyeki         ###   ########.fr       */
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
	else if (key == KEY_RI)
	{

	}
	else if (key == KEY_LE)
	{

	}
	return (0);
}

