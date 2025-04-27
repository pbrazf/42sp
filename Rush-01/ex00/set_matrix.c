/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <gcruz-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:54:10 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/27 14:57:35 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function intializes the entire matrix with zeros(empty).
// It prepares the 6x6 matrix to be ready for clues and later the solutions.
// - row: used to iterate through the rows of the matrix.
// - col: used to iterate through the columns of the matrix.
void	initialize_matrix(int matrix[6][6])
{
	int	row;
	int	col;

	row = 0;
	while (row < 6)
	{
		col = 0;
		while (col < 6)
		{
			matrix[row][col] = 0;
			col++;
		}
		row++;
	}
}

// Places the 16 clues around the edges of the matrix.
// The clues are divided into top, bottom, left, and right sides.
// Variables:
// - matrix: the 6x6 matrix where the clues will be placed.
// - clues: array of 16 integers containing the clues.
// - i: used as an index to iterate through the clues.
void	put_clues_in_matrix(int matrix[6][6], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[0][i + 1] = clues[i];
		matrix[5][i + 1] = clues[i + 4];
		matrix[i + 1][0] = clues[i + 8];
		matrix[i + 1][5] = clues[i + 12];
		i++;
	}
}

// Builds the matrix by first initializing it with zeros
// and then placing the clues on its borders.
// Variables:
// - matrix: the 6x6 matrix to be built.
// - clues: array of 16 integers containing the clues.
void	build_matrix(int matrix[6][6], int *clues)
{
	initialize_matrix(matrix);
	put_clues_in_matrix(matrix, clues);
}
