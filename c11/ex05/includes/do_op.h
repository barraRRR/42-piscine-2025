/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:06:49 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/18 18:03:44 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

typedef enum operation
{
	ADD,
	SUBTRACK,
	MULTIPLY,
	DIVISION,
	MODULO
}	t_operation;

int		ft_add(int a, int b);
int		ft_subtrack(int a, int b);
int		ft_multiply(int a, int b);
int		ft_division(int a, int b);
int		ft_modulo(int a, int b);
void	ft_putstr(char *str);
int		ft_atoi(char *num);
void	ft_putnbr(int nbr);

int		(*g_op[5])(int, int) = {
	ft_add,
	ft_subtrack,
	ft_multiply,
	ft_division,
	ft_modulo
};

#endif
