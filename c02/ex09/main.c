/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:49:41 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/03 19:49:50 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[63] = "salut, comMent tu Vas ?  42mots quArante-Deux; cinquante+et+un";

	ft_strcapitalize(str);
	printf("%s\n", str);
	return (0);
}
