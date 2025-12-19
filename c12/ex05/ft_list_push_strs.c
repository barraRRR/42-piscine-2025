/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 08:25:47 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/19 09:01:42 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	free_partial(t_list *begin_list)
{
	t_list		*ptr;

	while (begin_list)
	{
		ptr = begin_list;
		begin_list = begin_list->next;
		free(ptr);
	}
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	t_list	*node;
	int		i;

	if (!strs || size <= 0)
		return (NULL);
	begin_list = NULL;
	i = 0;
	while (i < size)
	{
		node = ft_create_elem(strs[i]);
		if (!node)
		{
			free_partial(begin_list);
			return (NULL);
		}
		node->next = begin_list;
		begin_list = node;
		i++;
	}
	return (begin_list);
}
