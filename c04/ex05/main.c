/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:34:28 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/04 18:35:00 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi_base(char *str, char *base);

int main(void)
{
	char *base8      = "galimero";          // base 8 (8 símbolos)
	char *base5      = "CeLtA";             // base 5
	//char *base13     = "0123456789qwe";     // base 13
	char *baseFail1  = "J";                 // tamaño 1 → inválida
	char *baseFail2  = "jajaja";            // repetida → inválida
	char *baseFail3  = "54 23";             // espacio → inválida
	//char *baseFail4  = "34+56-78";          // + o - → inválida

	int	atoi8_1 = ft_atoi_base("galgalmal" ,base8);
	int	atoi8_2 = ft_atoi_base("   --+-galgalmal" ,base8);
	int	atoi8_3 = ft_atoi_base("8galgalmal" ,base8);

	int	atoi5_1 = ft_atoi_base("etA" ,base5);
	int	atoi5_2 = ft_atoi_base("CetAC" ,base5);
	int	atoi5_3 = ft_atoi_base(" AAioAetA" ,base5);

	int	atoiF_1 = ft_atoi_base("jjj" ,baseFail1);
	int	atoiF_2 = ft_atoi_base(" 54   3233" ,baseFail2);
	int	atoiF_3 = ft_atoi_base(" AAioAetA" ,baseFail3);

	printf("--- Batería de tests ---\n");

	printf("Resultado de galgalmal en base %s: %i\n", base8, atoi8_1);
	printf("Resultado de    --+-galgalmal en base %s: %i\n", base8, atoi8_2);
	printf("Resultado de 8galgalmal en base %s: %i\n", base8, atoi8_3);

	printf("Resultado de etA en base %s: %i\n", base5, atoi5_1);
	printf("Resultado de CetAC en base %s: %i\n", base5, atoi5_2);
	printf("Resultado de  AAioAetA en base %s: %i\n", base5, atoi5_3);

	printf("Resultado de jjj en base %s: %i\n", baseFail1, atoiF_1);
	printf("Resultado de  54   3233 en base %s: %i\n", baseFail2, atoiF_2);
	printf("Resultado de  AAioAetA en base %s: %i\n", baseFail2, atoiF_3);
	return (0);
}
