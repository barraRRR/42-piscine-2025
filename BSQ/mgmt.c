/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mgmt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:25:26 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/26 17:27:51 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int	sq_size(char **map, int i, int j, int resize)
{
	int		ni;
	int		nj;
	int		cursor;

	ni = i + resize;
	nj = j + resize;
	cursor = j;
	if (!map[ni] || !map[i][nj] || map[i][nj] == '\n')
		return (resize);
	while (cursor <= nj)
	{
		if (is_obs(map, map[i][cursor]) || is_obs(map, map[ni][cursor]))
			return (resize);
		cursor++;
	}
	cursor = i;
	while (cursor <= ni)
	{
		if (is_obs(map, map[cursor][j]) || is_obs(map, map[cursor][nj]))
			return (resize);
		cursor++;
	}
	return (sq_size(map, i, j, resize + 1));
}

int	sq_finder(char **map, char emp, t_list **list, int max_size)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_emp(emp, map[i][j]))
			{
				size = sq_size(map, i, j, 1);
				if (size > max_size)
				{
					max_size = size;
					if (!save_sq(size, i, j, list))
						return (0);
				}
			}
			j++;
		}
	}
	return (1);
}

void    colour_bs(char **map, char sq, t_list **list)
{
    t_list  *ptr;
    int     i;
    int     j;
    int     ni;
    int     nj;

    ptr = *list;
    while (ptr->next)
        ptr = ptr->next;
    i = ptr->i;
    ni = i + ptr->size;
    nj = ptr->j + ptr->size;
    while (i < ni)
    {
        j = ptr->j;
        while (j < nj)
        {
            map[i][j] = sq;
            j++;
        }
        i++;
    }
}

void    print_map(char **map)
{
    int     i;

    i = 0;
    while (map[i])
        ft_putstr(map[i++]);
    ft_putstr("\n");
}

char    **map_mgmt(char *map_path, t_list **list)
{
    char    **map;
    char    emp;
    char    obs;
    char    sq;

    map = read_map(map_path, 0, 0);
	if (!map)
		return (NULL);
	if (!map_validator(map, &emp, &obs, &sq))
	{
		free_total(map);
		return (NULL);
	}
    if (!sq_finder(map, emp, list, 0))
        return (NULL);
    colour_bs(map, sq, list);
    return (map);
}