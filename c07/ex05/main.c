/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:29:31 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/02 09:01:37 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

char    **ft_split(char *str, char *charset);

int main(void)
{
    int     i;
    char    **arr;
    char    *str = "fantastic+-do+-the+-bombastic";

    arr = ft_split(str, "+-");
    if (!arr || arr[0] == NULL)
    {
        free(arr);
        return (1);
    }

    i = 0;
    while (arr && arr[i])
    {
        printf("Word %i: %s\n", i, arr[i]);
        i++;
    }
    i = 0;
    while (arr && arr[i])
        free(arr[i++]);
    free(arr);
    return (0);
}
