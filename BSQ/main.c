/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:00:48 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 19:44:38 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>

static int	one_arg(char **map, t_list *begin)
{
	map = map_from_stdin(&begin);
	if (!map)
	{
		ft_putstr("map error\n");
		return (0);
	}
	print_map(map);
	free_list(begin);
	free_total(map);
	return (1);
}

static int	multiple_arg(char *pathname, char **map, t_list *begin)
{
	begin = NULL;
	map = map_mgmt(pathname, &begin);
	if (!map)
	{
		ft_putstr("map error\n");
		return (0);
	}
	print_map(map);
	free_list(begin);
	free_total(map);
	return (1);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_list	*begin;
	int		i;

	map = NULL;
	begin = NULL;
	if (argc == 1)
	{
		if (!one_arg(map, begin))
			return (1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!multiple_arg(argv[i], map, begin))
			return (1);
		i++;
	}
	return (0);
}