/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 09:59:20 by jbarreir          #+#    #+#             */
/*   Updated: 2025/12/06 08:50:41 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(char board[10][10])
{
	int		x;
	int		y;
	char	c;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (board[y][x] != '*')
			{
				c = y + '0';
				write(1, &c, 1);
				break ;
			}
			y++;
		}
		x++;
	}
	write(1, "\n", 1);
}

int	queen_check(int queen_row, int c, int x, int y)
{
	int		dx;
	int		dy;

	if (queen_row == y)
		return (0);
	dy = queen_row - y;
	dx = x - c;
	if (dy < 0)
		dy = -dy;
	if (dx < 0)
		dx = -dx;
	if (dy == dx)
		return (0);
	return (1);
}

int	queen_find(int c, int x, int y, char board[10][10])
{
	int		r;
	int		queen_row;

	while (++c < 10)
	{
		if (c == x)
		{
			c++;
			continue ;
		}
		r = 0;
		queen_row = -1;
		while (r < 10)
		{
			if (board[r][c] != '*')
			{
				queen_row = r;
				break ;
			}
			r++;
		}
		if (queen_row != -1 && !queen_check(queen_row, c, x, y))
			return (0);
	}
	return (1);
}

int	gen_board(int x, char board[10][10])
{
	int		i;
	int		count;

	if (x == 10)
	{
		print_solution(board);
		return (1);
	}
	count = 0;
	i = 0;
	while (i < 10)
	{
		if (queen_find(-1, x, i, board))
		{
			board[i][x] = (char)(i + '0');
			count += gen_board(x + 1, board);
			board[i][x] = '*';
		}
		i++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10][10];
	int		count;
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = '*';
			j++;
		}
		i++;
	}
	count = gen_board(0, board);
	return (count);
}
