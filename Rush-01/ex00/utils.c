/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <gcruz-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:36:53 by maria-ol          #+#    #+#             */
/*   Updated: 2025/04/27 15:34:05 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid(int matrix[6][6], int row, int col, int num)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (matrix[row][i] == num)
			return (0);
		i++;
	}
	i = 1;
	while (i <= 4)
	{
		if (matrix[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	is_row_complete(int matrix[6][6], int row)
{
	int	col;

	col = 1;
	while (col <= 4)
	{
		if (matrix[row][col] == 0)
			return (0);
		col++;
	}
	return (1);
}

int	is_col_complete(int matrix[6][6], int col)
{
	int	row;

	row = 1;
	while (row <= 4)
	{
		if (matrix[row][col] == 0)
			return (0);
		row++;
	}
	return (1);
}

int	check_row_constraints(int matrix[6][6], int row)
{
	if (count_visible_from_left(matrix, row) != matrix[row][0])
		return (0);
	if (count_visible_from_right(matrix, row) != matrix[row][5])
		return (0);
	return (1);
}

int	check_col_constraints(int matrix[6][6], int col)
{
	if (count_visible_from_top(matrix, col) != matrix[0][col])
		return (0);
	if (count_visible_from_bottom(matrix, col) != matrix[5][col])
		return (0);
	return (1);
}
