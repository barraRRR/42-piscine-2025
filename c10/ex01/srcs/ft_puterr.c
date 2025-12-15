/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:36:02 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/12 16:43:54 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_puterr(char *prog, char *file)
{
	char	*bprog;

	bprog = basename(prog);
	write(2, bprog, ft_strlen(bprog));
	write(2, ": \"", 3);
	write(2, file, ft_strlen(file));
	write(2, "\":  ", 3);
	strerror(errno);
}
