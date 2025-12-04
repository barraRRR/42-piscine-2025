/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:56:46 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/04 17:57:01 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int		ft_strlen(char *str);

int	main(void)
{
	char	dest[1000] = "Hola y";
	char	src[1000] = " adios!\n";
	unsigned int	len;

	len = ft_strlcat(dest, src, 20);
	printf("Dest: %s\n", dest);
	printf("El resultado de strlcat es: %i", len);
	return (0);
}
