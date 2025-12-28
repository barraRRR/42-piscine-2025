/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:40:07 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 18:41:15 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

void	free_partial(char **map, int allocated)
{
	int		i;

	i = 0;
	while (i < allocated)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_total(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	**mem_map(int x, int y)
{
	char	**map;
	int		i;
	int		j;

	map = malloc(sizeof(char *) * (y + 2));
	if (!map)
		return (NULL);
	i = 0;
	while (i <= y)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * (x + 2));
		if (!map[i])
		{
			free_partial(map, i - 1);
			return (NULL);
		}
		while (j < (x + 2))
			map[i][j++] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}