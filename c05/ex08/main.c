/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:46:14 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/05 12:48:35 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ten_queens_puzzle(void);

int	main(void)
{
	int		solutions;

	solutions = ft_ten_queens_puzzle();
	printf("\nNumber of solutions: %i\n", solutions);
	return (0);
}
