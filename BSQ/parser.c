/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:07:08 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/28 18:38:45 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_emp(char emp, char c)
{
	return (emp == c);
}

int	is_obs(char **map, char c)
{
	int		i;
	char	obs;

	i = 0;
	while ((map[0][i] >= '0' && map[0][i] <= '9'))
		i++;
	obs = map[0][i + 1];
	return (obs == c);
}

int first_line(char **map, char *emp, char *obs, char *sq)
{
    int     len;
    int     i;

    if (!map || !map[0])
        return (0);
    len = 0;
    while (map[0][len] && map[0][len] != '\n')
    {
        if (map[0][len] < 32 || map[0][len] > 126)
            return (0);
        len++;
    }
    i = 0;
    while (i < len - 3)
    {
        if (map[0][i] < '0' || map[0][i] > '9')
            return (0);
		i++;
    }
    *sq = map[0][len - 1];
    *obs = map[0][len - 2];
    *emp = map[0][len - 3];
    return (1);
}

int rest_of_lines(char **map, char *emp, char *obs)
{
    int     line_len;
    int     i;
    int     j;

    line_len = 0;
    while (map[1][line_len] && map[1][line_len] != '\n')
        line_len++;
    i = 2;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '\n')
                break ;
            if (map[i][j] != *emp && map[i][j] != *obs)
				return (0);
            j++;
        }
        if (!map[i][j] || j != line_len)
            return (0);
        i++;
    }
    return (1);
}

int	map_validator(char **map, char *emp, char *obs, char *sq)
{
	if (!first_line(map, emp, obs, sq))
		return (0);
	if (*emp == *obs || *emp == *sq || *obs == *sq)
		return (0);
	if (!rest_of_lines(map, emp, obs))
		return (0);
	return (1);
}