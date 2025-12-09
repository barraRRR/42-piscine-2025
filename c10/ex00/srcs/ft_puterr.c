/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:36:02 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/08 09:38:15 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include <unistd.h>

void	ft_puterr(char *str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}
