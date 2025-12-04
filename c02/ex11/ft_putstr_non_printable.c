/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:13:27 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/04 11:50:59 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	tohex(unsigned char uc)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[(uc / 16) % 16]);
	ft_putchar(base[uc % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			tohex(str[i]);
		}
		i++;
	}
}
