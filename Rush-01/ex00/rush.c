#include "header.h"

int	solve_try_number(int matrix[6][6], int row, int col, int num)
{
	matrix[row][col] = num;
	if (is_row_complete(matrix, row) && !check_row_constraints(matrix, row))
		matrix[row][col] = 0;
	else if (is_col_complete(matrix, col)
		&& !check_col_constraints(matrix, col))
		matrix[row][col] = 0;
	else if (solve_matrix(matrix, row, col + 1))
		return (1);
	matrix[row][col] = 0;
	return (0);
}

int	solve_matrix(int matrix[6][6], int row, int col)
{
	int	num;

	num = 1;
	if (row == 5)
		return (check_clues(matrix)); // SUCESSO
	if (col == 5)
		return (solve_matrix(matrix, row + 1, 1)); // PASSA PRA PROXIMA LINHA
	if (matrix[row][col] != 0)
		return (solve_matrix(matrix, row, col + 1)); // PASSA PRA PROXIMA CASA
	while (num <= 4)
	{
		if (is_valid(matrix, row, col, num))
		{
			if (solve_try_number(matrix, row, col, num))
				return (1);
		}
		num++;
	}
	return (0);
}
