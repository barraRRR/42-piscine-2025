/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:56:00 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/04 16:35:57 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	void	*str = "Bonjour les aminches...c. est fou.tout.ce qu on peut faire avec...print memory....lol.lol. .";

	printf("%p\n", str);
	printf("\n");

	ft_print_memory(str, 95);
	return (0);
}
