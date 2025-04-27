/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria-ol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:36:53 by maria-ol          #+#    #+#             */
/*   Updated: 2025/04/26 12:39:05 by maria-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int	count_visible_from_top(int matrix[6][6], int col);
int	count_visible_from_bottom(int matrix[6][6], int col);
int	count_visible_from_left(int matrix[6][6], int row);
int	count_visible_from_right(int matrix[6][6], int row);

int	check_clues(int matrix[6][6])
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (count_visible_from_top(matrix, i) != matrix[0][i])
			return (0);
		if (count_visible_from_bottom(matrix, i) != matrix[5][i])
			return (0);
		if (count_visible_from_left(matrix, i) != matrix[i][0])
			return (0);
		if (count_visible_from_right(matrix, i) != matrix[i][5])
			return (0);
		i++;
	}
	return (1); // Todas pistas ok
}

int	count_visible_from_top(int matrix[6][6], int col)
{
	int	max_height;
	int	count;
	int	row;

	max_height = 0;
	count = 0;
	row = 1;
	while (row <= 4)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		row++;
	}
	return (count);
}

int	count_visible_from_bottom(int matrix[6][6], int col)
{
	int	max_height;
	int	count;
	int	row;

	max_height = 0;
	count = 0;
	row = 4;
	while (row >= 1)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		row--;
	}
	return (count);
}

int	count_visible_from_left(int matrix[6][6], int row)
{
	int	max_height;
	int	count;
	int	col;

	max_height = 0;
	count = 0;
	col = 1;
	while (col <= 4)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		col++;
	}
	return (count);
}

int	count_visible_from_right(int matrix[6][6], int row)
{
	int	max_height;
	int	count;
	int	col;

	max_height = 0;
	count = 0;
	col = 4;
	while (col >= 1)
	{
		if (matrix[row][col] > max_height)
		{
			max_height = matrix[row][col];
			count++;
		}
		col--;
	}
	return (count);
}

int	is_valid(int matrix[6][6], int row, int col, int num)
{
	int	i;

	// Verifica linha
	i = 1;
	while (i <= 4)
	{
		if (matrix[row][i] == num)
			return (0);
		i++;
	}

	// Verifica coluna
	i = 1;
	while (i <= 4)
	{
		if (matrix[i][col] == num)
			return (0);
		i++;
	}

	return (1); // Válido
}

int	is_row_complete(int matrix[6][6], int row)
{
	int	col = 1;
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
	int	row = 1;
	while (row <= 4)
	{
		if (matrix[row][col] == 0)
			return (0);
		row++;
	}
	return (1);
}

int	solve_matrix(int matrix[6][6], int row, int col)
{
	int	num;

	if (row == 5) // Se passou da última linha, está resolvido
		return (check_clues(matrix)); // Confirma se as pistas são válidas

	if (col == 5) // Se passou da última coluna, vai para a próxima linha
		return (solve_matrix(matrix, row + 1, 1));

	if (matrix[row][col] != 0) // Pula se já estiver preenchido
		return (solve_matrix(matrix, row, col + 1));

	num = 1;
	while (num <= 4)
	{
		if (is_valid(matrix, row, col, num)) // Testa se pode colocar
		{
			matrix[row][col] = num;

			// 🔥 Validação Parcial 🔥
			if (is_row_complete(matrix, row))
			{
				if (count_visible_from_left(matrix, row) != matrix[row][0])
				{
					matrix[row][col] = 0;
					num++;
					continue;
				}
				if (count_visible_from_right(matrix, row) != matrix[row][5])
				{
					matrix[row][col] = 0;
					num++;
					continue;
				}
			}
			if (is_col_complete(matrix, col))
			{
				if (count_visible_from_top(matrix, col) != matrix[0][col])
				{
					matrix[row][col] = 0;
					num++;
					continue;
				}
				if (count_visible_from_bottom(matrix, col) != matrix[5][col])
				{
					matrix[row][col] = 0;
					num++;
					continue;
				}
			}
			// 🔥 Continua Recursivamente 🔥
			if (solve_matrix(matrix, row, col + 1))
				return (1); // Se deu certo, retorna sucesso

			matrix[row][col] = 0; // Se não, volta atrás (backtrack)
		}
		num++;
	}
	return (0); // Se nenhum número serviu, falhou
}
