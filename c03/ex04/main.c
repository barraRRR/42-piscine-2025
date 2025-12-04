/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:54:00 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/04 17:54:08 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	s1[1000] = "Evaluador, como suspendas a Javi me autodestruiré";
	char	s2[1000] = "Javi";
	char	*cat;

	cat = ft_strstr(s1, s2);
	printf("El resultado de strstr es: %s", cat);
	return (0);
}
