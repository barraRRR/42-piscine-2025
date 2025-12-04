/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:55:04 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/04 17:28:31 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	tohex(char uc)
{
	char	*base;

	base = "0123456789abcdef";
	ft_putchar(base[uc / 16]);
	ft_putchar(base[uc % 16]);
}

void	ft_putstr(char *str, unsigned int len)
{
	unsigned int		i;
	
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	print_line(char *str, unsigned int line_size)
{
	unsigned int	i;
	unsigned int	sp;
	unsigned int	fil;

	sp = 40;
	fil = 1;
	i = 0;
	while (fil < 40 && i < line_size)
	{
		tohex(str[i++]);
		fil += 2;
		if (fil % 5 == 0)
		{
			ft_putchar(' ');
			fil++;
		}
	}
	while (fil <= sp)
	{
		ft_putchar(' ');
		fil++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				k;
	unsigned long	p;
	char			*ptr;
	unsigned int	line_size;
	char			buf[16];

	if (size == 0 || !addr)
		return (addr);
	ptr = (char *)addr;
	i = 0;
	while (i < size)
	{
		p = (unsigned long)(ptr + i);
		k = 15;
		while (k >= 0)
		{
			buf[k] = "0123456789abcdef"[p % 16];
			p /= 16;
			k--;
		}
		ft_putstr(buf, 16);
		write(1, ": ", 2);
		if ((size - i) > 16)
			line_size = 16;
		else
			line_size = size - i;
		print_line(ptr + i, line_size);
		ft_putstr(ptr + i, line_size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
