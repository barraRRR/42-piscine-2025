/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 12:54:03 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 18:41:10 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int				i;
	int				result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

t_list	*create_node(int size, int i, int j)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->j = j;
	node->i = i;
	node->size = size;
	node->next = NULL;
	return (node);
}

int	save_sq(char size, int i, int j, t_list **begin)
{
	t_list	*new;
	t_list	*ptr;

	new = create_node(size, i, j);
	if (!new)
		return (0);
	if (!*begin)
	{
		*begin = new;
		return (1);
	}
	ptr = *begin;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (1);
}