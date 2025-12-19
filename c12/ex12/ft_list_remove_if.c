/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:51:59 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/19 15:29:20 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list		*cur;
	t_list		*tmp;
	t_list		*pre;

	if (!begin_list || !*begin_list || !cmp || !free_fct)
		return ;
	cur = *begin_list;
	pre = NULL;
	while (cur)
	{
		if (!cmp(cur->data, data_ref))
		{
			tmp = cur;
			if (!pre)
				*begin_list = cur->next;
			else
				pre->next = cur->next;
			cur = cur->next;
			free_fct(tmp->data);
			free(tmp);
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}
