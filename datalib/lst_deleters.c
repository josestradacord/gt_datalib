/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_deleters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgutier <frgutier@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:58:54 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/29 13:38:33 by frgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "datalib.h"

void	lst_remove_first(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	lst_remove(t_list **list, t_list *elem)
{
	t_list	*tmp;

	if (*list)
	{
		if (*list == elem)
			lst_remove_first(list);
		else
		{
			tmp = *list;
			while (tmp->next != elem)
				tmp = tmp->next;
			tmp->next = elem->next;
			free(elem);
		}
	}
}

void	lst_remove_last(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		if ((*list)->next == NULL)
			lst_remove_first(list);
		else
		{
			tmp = *list;
			while (tmp->next->next != NULL)
				tmp = tmp->next;
			free(tmp->next);
			tmp->next = NULL;
		}
	}
}

int	lst_purge(t_list **list, void *data)
{
	t_list	*tmp;

	if (*list)
	{
		if ((*list)->data == data)
			lst_remove_first(list);
		else
		{
			tmp = *list;
			while (tmp->next->data != data)
				tmp = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp->next);
		}
	}
	return (0);
}

void	lst_clear(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			free(*list);
			*list = tmp;
		}
	}
}
