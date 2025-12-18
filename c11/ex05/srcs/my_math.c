/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:33:58 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/18 18:02:03 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_subtrack(int a, int b)
{
	return (a - b);
}

int	ft_multiply(int a, int b)
{
	return (a * b);
}

int	ft_division(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a / b);
}

int	ft_modulo(int a, int b)
{
	if (b == 0)
		return (0);
	else
		return (a % b);
}
