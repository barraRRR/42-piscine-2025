/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:13:05 by jbarreir          #+#    #+#             */
/*   Updated: 2025/11/26 19:29:19 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int     is_space(char c)
{    
    return (c == ' ' || (c >= 9 && c <= 13));
}

static size_t  word_count(char *str)
{
    size_t  i;
    size_t  words;

    i = 0;
    words = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            words++;
            while (str[i] && !is_space(str[i]))
                i++;
        }
    }
    return (words);
}

static size_t   word_len(char *str)
{
    size_t  len;
    
    len = 0;
    while (str[len] && !is_space(str[len]))
        len++;
    return (len);
}

void    ft_free_split(char **arr)
{
    size_t  i;

    i = 0;
    if (!arr)
        return ;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

static char *alloc_and_copy(char *start, size_t len)
{
    char    *dst;
    size_t  i;

    dst = malloc(len + 1);
    if (!dst)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dst[i] = start[i];
        i++;
    }
    dst[len] = '\0';
    return (dst);
}

static void free_partial(char **arr, size_t filled)
{
    size_t  i;
    
    if (!arr)
        return ;
    i = 0;
    while (i < filled)
        free(arr[i++]);
    free(arr);
}

char    **ft_split(char *str)
{
    char    **arr;
    size_t  i;
    size_t  words;
    size_t  w;

    if (!str)
    {
        arr = (char **)malloc(sizeof(char *));
        if (!arr)
            return (NULL);
        arr[0] = NULL;
        return (arr);
    }
    words = word_count(str);
    arr = (char **)malloc(sizeof(char *) * (words + 1));
    if (!arr)
        return (NULL);
    w = 0;    
    i = 0;
    while (str[i])
    {
        while (is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            size_t  wlen;
            wlen = word_len(str + i);
            arr[w] = alloc_and_copy(str + i, wlen);
            if (!arr[w])
                free_partial(arr, w);
            w++;
            i += wlen;
        }
    }
    arr[w] = NULL;
    return (arr);
}

// ---------------------------
//   Ejemplo de main de prueba
// ---------------------------

#include <stdio.h>

int main(void)
{
    char **arr;
    size_t i;

    arr = ft_split("  hola\tmundo\nesto es\tuna prueba  ");
    for (i = 0; arr && arr[i]; i++)
        printf("word %zu: \"%s\"\n", i, arr[i]);
    ft_free_split(arr);
    return 0;
}
/*
   Salida esperada:
   word 0: "hola"
   word 1: "mundo"
   word 2: "esto"
   word 3: "es"
   word 4: "una"
   word 5: "prueba"
*/



















