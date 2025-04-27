/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:21:47 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/20 18:28:42 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	print_char(int line, int col, int last_line, int last_col);
void	rect_logic(int last_col, int last_line);

void	rush(int x, int y)
{
	int	last_line;
	int	last_col;

	if (x <= 0 || y <= 0)
	{
		write(1, "Error: Invalid Dimension(s)!!\n", 30);
	}
	else
	{
		last_line = y - 1;
		last_col = x - 1;
		rect_logic(last_col, last_line);
	}
}

void	rect_logic(int last_col, int last_line)
{
	int	line;
	int	col;

	line = 0;
	while (line <= last_line)
	{
		col = 0;
		while (col <= last_col)
		{
			print_char(line, col, last_line, last_col);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}

void	print_char(int line, int col, int last_line, int last_col)
{
	char	character;

	character = ' ';
	if ((line == 0 && col == 0) || (line == last_line && col == last_col))
	{
		character = 'A';
	}
	else if ((line == 0 && col == last_col)
		|| (line == last_line && col == 0))
	{
		character = 'C';
	}
	else if (line == 0 || line == last_line
		|| col == 0 || col == last_col)
	{
		character = 'B';
	}
	ft_putchar(character);
}
