/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:12:49 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/03 19:58:15 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_low(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_up(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	alphnum(char c)
{
	return ((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	if (!str)
		return (NULL);
	if (is_low(str[0]))
		str[0] -= 32;
	i = 1;
	while (str && str[i])
	{
		if (is_low(str[i]) && !alphnum(str[i - 1]))
			str[i] -= 32;
		else if (is_up(str[i]) && alphnum(str[i - 1]))
			str[i] += 32;
		i++;
	}
	return (str);
}
