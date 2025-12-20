/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 12:36:38 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/20 12:56:21 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list		*ptr1;
	t_list		*ptr2;
	t_list		*cur;

	if (!begin_list1 || !cmp)
		return ;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	ptr1 = *begin_list1;
	ptr2 = begin_list2;
	if (cmp(ptr2->data, ptr1->data) < 0)
	{
		*begin_list1 = ptr2;
		ptr2 = ptr2->next;
	}
	else
	{
		*begin_list1 = ptr1;
		ptr1 = ptr1->next;
	}
	cur = *begin_list1;
	while (ptr1 && ptr2)
	{
		if (cmp(ptr1->data, ptr2->data) < 0)
		{
			cur->next = ptr1;
			ptr1 = ptr1->next;
		}
		else
		{
			cur->next = ptr2;
			ptr2 = ptr2->next;
		}
		cur = cur->next;
	}
	if (ptr1)
		cur->next = ptr1;
	else
		cur->next = ptr2;
}
