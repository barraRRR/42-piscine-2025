/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:47:21 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/19 17:26:30 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*tmp;
	int		swap;

	if (!begin_list || !*begin_list || !cmp)
		return ;
	swap = 1;
	while (swap)
	{
		ptr = *begin_list;
		swap = 0;
		while (ptr->next)
		{
			if (cmp(ptr->data, ptr->next->data) > 0)
			{
				tmp = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tmp;
				swap = 1;
			}
			ptr = ptr->next;
		}
	}
}
