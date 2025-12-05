/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 13:38:29 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/05 08:49:07 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	what(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else if (c == '+' || c == '-')
		return (2);
	else
		return (0);
}

int	isbase(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	checkbase(char *base, int baselen)
{
	int		i;
	int		j;

	i = 0;
	if (baselen < 2)
		return (0);
	while (i < baselen)
	{
		j = i + 1;
		while (j < baselen)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (what(base[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

long	base_to_n(char *str, char *base, int baselen, int i)
{
	long	n;
	int		k;

	n = 0;
	while (isbase(str[i], base))
	{
		k = 0;
		while (base[k])
		{
			if (str[i] == base[k])
			{
				n = (n * baselen) + k;
				break ;
			}
			k++;
		}
		i++;
	}
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int		baselen;
	long	n;
	int		i;
	int		sign;

	if (!str || !base)
		return (0);
	baselen = 0;
	while (base[baselen])
		baselen++;
	sign = 1;
	if (!(checkbase(base, baselen)))
		return (0);
	i = 0;
	while (what(str[i]) == 1)
		i++;
	while (what(str[i]) == 2)
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	n = base_to_n(str, base, baselen, i);
	return (n * sign);
}
