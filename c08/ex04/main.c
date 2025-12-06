/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:57:55 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/06 12:07:12 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strs_to_tab.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc, argv);
	i = 0;
	printf("--- TESTS ---\n");
	while (i < argc)
	{
		printf("TAB #%i\n", i);
		printf("size: %i\n", tab[i].size);
		printf("str: %p\n", tab[i].str);
		printf("copy: %s\n", tab[i].copy);
		printf("\n");
		i++;
	}
	i = 0;
	while (i < argc)
		free(tab[i++].copy);
	free(tab);
	return (0);
}
