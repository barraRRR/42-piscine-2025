/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_from_stdin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:43:24 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 19:50:32 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>

static int	f_take_y(char *buf)
{
	int		i;
    int     len;
    char    *chunk;

	i = 0;
	len = 0;
	while (buf && buf[len] != '\n')
        len++;
    chunk = malloc(sizeof(char) * (len + 1));
    if (!chunk)
        return (0);
    while (i < len - 3)
    {
        if (buf[i] < '0' || buf[i] > '9')
            return (0);
        chunk[i] = buf[i];
        i++;
    }
	chunk[i] = '\0';
    i = ft_atoi(chunk);
    free(chunk);
	return (i);
}

static int	f_take_x(char *buf)
{
	int     i;
	int		x;
	int		new_line;

	new_line = 0;
    x = 0;
    i = 0;
	while (buf && buf[i] && new_line < 2)
	{
		if (buf[i] == '\n')
			new_line++;
		else if (new_line)
			x++;
        i++;
	}
	return (x);
}

static void  copy_map(char **map, char *buf, int y)
{
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
	while (buf[i] && i < BUF_SIZE && j <= y)
	{
		map[j][k] = buf[i++];
		if (map[j][k] == '\n')
		{
			k = 0;
			j++;
		}
		else
			k++;
	}
}

static int  read_stdin(char **map)
{
    ssize_t     bytes;
    int         x;
    int         y;
    char        buf[BUF_SIZE];

    bytes = read(0, buf, BUF_SIZE);
    if (bytes < 0)
        return (0);
    x = f_take_x(buf);
    y = f_take_y(buf);
    map = mem_map(x, y);
    if (!map)
        return (0);
    copy_map(map, buf, y);
	return (1);
}

char    **map_from_stdin(t_list **list)
{
    char    **map;
    char    emp;
    char    obs;
    char    sq;

    map = NULL;
    read_stdin(map);
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