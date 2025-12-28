/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_from_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:04:01 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 19:38:03 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>

static int	f_take_y(char *pathname)
{
	int		i;
	char	c;
	int		fd;
	char	buf[BUF_SIZE];
	ssize_t	bytes;

	i = 0;
	c = '\0';
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (0);
	while (c != '\n')
	{
		bytes = read(fd, &c, 1);
		if (bytes < 0)
		{
			close(fd);
			return (0);
		}
		buf[i++ % BUF_SIZE] = c;
	}
	buf[i] = '\0';
	close(fd);
	return (ft_atoi(buf));
}

static int	f_take_x(char *pathname, int x)
{
	char	c;
	int		bytes;
	int		fd;
	int		new_line;

	new_line = 0;
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (0);
	bytes = 1;
	while (bytes > 0 && new_line < 2)
	{
		bytes = read(fd, &c, 1);
		if (bytes < 0)
		{
			close(fd);
			return (0);
		}
		if (c == '\n')
			new_line++;
		else if (new_line)
			x++;
	}
	return (x);
}

int	bytes_reader(int *bytes, int fd, char *buf)
{
	*bytes = read(fd, buf, BUF_SIZE);
	if (*bytes < 0)
		return (0);
	return (1);
}

int	fill_map(char **map, int fd, int y, int j)
{
	int		i;
	int		k;
	int		bytes;
	char	buf[BUF_SIZE];

	k = 0;
	bytes = 1;
	while (bytes > 0)
	{
		if (!bytes_reader(&bytes, fd, buf))
			return (0);
		i = 0;
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
	return (1);
}

char	**read_map(char *pathname, int x, int y)
{
	char	**map;
	int		fd;

	x = f_take_x(pathname, 0);
	y = f_take_y(pathname);
	if (x < 1 || y < 1)
		return (NULL);
	map = mem_map(x, y);
	if (!map)
		return (NULL);
	fd = open(pathname, O_RDONLY);
	if (fd < 0)
	{
		free_total(map);
		return (NULL);
	}
	if (!fill_map(map, fd, y, 0))
	{
		free_total(map);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}