/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:13:28 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/18 13:47:16 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	loop(int sort_sign, int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	while (i < length - 1)
	{
		if ((sort_sign == 1) && (f(tab[i], tab[i + 1]) < 0))
			return (0);
		if ((sort_sign == -1) && (f(tab[i], tab[i + 1]) > 0))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (loop(1, tab, length, f))
		return (1);
	else if (loop(-1, tab, length, f))
		return (1);
	else
		return (0);
}
