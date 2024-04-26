/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:57:47 by seohyeki          #+#    #+#             */
/*   Updated: 2024/04/27 00:01:25 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "util.h"

static t_list	*ft_lstlast_prev(t_list *lst)
{
	t_list	*prev;

	prev = NULL;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			prev = lst;
			lst = lst->next;
		}
	}
	return (prev);
}

static void	trim_start_node(t_list **map)
{
	t_list	*tmp;

	while (*map != NULL)
	{
		if (is_emptyline((char *)(*map)->content) == 0)
			return ;
		else
		{
			tmp = *map;
			*map = (*map)->next;
			ft_lstdelone(tmp, free);
		}
	}
}

static void	trim_end_node(t_list **map, t_list *head)
{
	while (1)
	{
		*map = ft_lstlast_prev(*map);
		if (is_emptyline((char *)(*map)->next->content) == 0)
		{
			*map = head;
			return ;
		}
		else
		{
			ft_lstdelone((*map)->next, free);
			(*map)->next = NULL;
			*map = head;
		}
	}
}

static void	delete_newline(t_list **map)
{
	t_list	*head;
	size_t	i;

	head = *map;
	while (*map)
	{
		i = 0;
		while (((char *)(*map)->content)[i] != '\0'
			&& ((char *)(*map)->content)[i] != '\n')
			i++;
		if (((char *)(*map)->content)[i] == '\n')
			((char *)(*map)->content)[i] = '\0';
		*map = (*map)->next;
	}
	*map = head;
}

void	ft_lst_trim(t_list **map)
{
	t_list	*head;

	trim_start_node(map);
	if (*map == NULL)
		error_exit("invalid map.");
	head = *map;
	trim_end_node(map, head);
	delete_newline(map);
}
