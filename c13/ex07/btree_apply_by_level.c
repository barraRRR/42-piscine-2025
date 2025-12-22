/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:17:54 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/22 14:04:22 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	enqueue(t_queue **head, t_queue **tail, t_btree *node, int level)
{
	t_queue		*new;

	new = malloc(sizeof(t_queue));
	if (!new)
		return ;
	new->node = node;
	new->level = level;
	new->next = NULL;
	if (!*tail)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
}

t_queue	*dequeue(t_queue **head, t_queue **tail)
{
	t_queue		*tmp;

	if (!*head)
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	if (!*head)
		*tail = NULL;
	return (tmp);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue		*head;
	t_queue		*tail;
	t_queue		*cur;
	int			prev_level;

	if (!root || !applyf)
		return ;
	head = NULL;
	tail = NULL;
	prev_level = -1;
	enqueue(&head, &tail, root, 0);
	while (head)
	{
		cur = dequeue(&head, &tail);
		applyf(cur->node->item, cur->level, cur->level != prev_level);
		if (cur->node->left)
			enqueue(&head, &tail, cur->node->left, cur->level + 1);
		if (cur->node->right)
			enqueue(&head, &tail, cur->node->right, cur->level + 1);
		prev_level = cur->level;
		free(cur);
	}
}
