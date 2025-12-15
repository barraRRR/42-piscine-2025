/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 08:33:09 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/12 16:46:21 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE];
	ssize_t	bytes;
	int		i;
   
	if (argc == 1)
	{
		while ((bytes = read(0, buf, BUF_SIZE)) > 0)
			write(1, buf, bytes);
		return (0);
	}
	i = 1;
	while (i < argc)
	{	
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			ft_puterr(argv[0], argv[i]);
			close(fd);
			return (1);
		}
		while ((bytes = read(fd, buf, BUF_SIZE)) > 0)
		{
			if (write(1, buf, bytes) == -1)
			{
				ft_puterr(argv[0], argv[i]);
				close(fd);
				return (1);
			}
		}
		if (bytes < 0)
		{
			ft_puterr(argv[0], argv[i]);
			close(fd);
			return (1);
		}
		close(fd);
		i++;
	}
	return (0);
}
