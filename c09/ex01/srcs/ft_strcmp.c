/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:53:28 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/07 08:39:44 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

int		ft_strcmp(char *s1, char *s2);

int		main(void)
{
	char	*s1;
	char	*s2;
	int		cmp;

	s1 = "Hola, mundo jajajaja \n";
	s2 = "Adios, mundo maldito!\n";
	cmp = ft_strcmp(s1, s2);
	printf("El resultado de strcmp es: %i", cmp);
	return (0);
}
*/

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
