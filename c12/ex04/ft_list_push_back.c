/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 22:21:15 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/18 22:44:27 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*node;
	t_list	*ptr;

	if (!begin_list)
		return ;
	node = ft_create_elem(data);
	if (!node)
		return ;
	if (*begin_list == NULL)
	{
		*begin_list = node;
		return ;
	}
	ptr = *begin_list;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = node;
}
