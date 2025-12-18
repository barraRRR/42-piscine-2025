/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:52:50 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/18 18:19:59 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	main(int argc, char **argv)
{
	int		a;
	int		b;

	if (argc != 4)
		return (1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	if (argv[2][0] == '+')
		ft_putnbr(g_op[ADD](a, b));
	else if (argv[2][0] == '-')
		ft_putnbr(g_op[SUBTRACK](a, b));
	else if (argv[2][0] == '*')
		ft_putnbr(g_op[MULTIPLY](a, b));
	else if (argv[2][0] == '/' && b != 0)
		ft_putnbr(g_op[DIVISION](a, b));
	else if (argv[2][0] == '/' && b == 0)
		ft_putstr("Stop : division by zero");
	else if (argv[2][0] == '%' && b != 0)
		ft_putnbr(g_op[MODULO](a, b));
	else if (argv[2][0] == '%' && b == 0)
		ft_putstr("Stop : modulo by zero");
	else
		ft_putnbr(0);
	ft_putstr("\n");
	return (0);
}
