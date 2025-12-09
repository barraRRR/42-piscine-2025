/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:48:24 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/08 09:44:25 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE];
	ssize_t	bytes;

	if (argc < 2)
	{
		ft_puterr("File name missing.\n");
		return (1);
	}
	if (argc > 2)
	{
		ft_puterr("Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_puterr("Cannot read file.\n");
		close(fd);		
		return (1);
	}
	while ((bytes = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (write(1, buf, bytes) == -1)
		{
			ft_puterr("Cannot read file.\n");
			close(fd);
			return (1);
		}
	}
	if (bytes < 0)
	{
		ft_puterr("Cannot read file.\n");
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
