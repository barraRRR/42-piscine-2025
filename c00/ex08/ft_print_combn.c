/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:06:20 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/03 18:59:21 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char c)
{
	write(1, &c, 1);
}

void	putcomb(char *buf, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		putchar(buf[i]);
		i++;
	}
	if (buf[0] != '0' + (10 - n))
		write(1, ", ", 2);
}

void	generate(int pos, int start, int n, char *buf)
{
	int		i;

	if (pos == n)
	{
		putcomb(buf, n);
			return ;
	}
	i = start;
	while (i <= 9)
	{
		buf[pos] = '0' + i;
		generate(pos + 1, i + 1, n, buf);
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];

	if (n <= 0 || n >= 10)
		return ;
	generate(0, 0, n, buf);
}
