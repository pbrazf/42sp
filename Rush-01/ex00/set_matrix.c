/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:54:10 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/26 19:18:29 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	top_clues(int matrix[6][6], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[0][i + 1] = clues[i];
		i++;
	}
}

void	bottom_clues(int matrix[6][6], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[5][i + 1] = clues[i + 4];
		i++;
	}
}

void	left_clues(int matrix[6][6], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[i + 1][0] = clues[i + 8];
		i++;
	}
}

void	right_clues(int matrix[6][6], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		matrix[i + 1][5] = clues[i + 12];
		i++;
	}
}

void	put_clues_in_matrix(int matrix[6][6], int *clues)
{
	top_clues(matrix, clues);
	bottom_clues(matrix, clues);
	left_clues(matrix, clues);
	right_clues(matrix, clues);
}

void	build_matrix(int matrix[6][6], int *clues)
{
	initialize_matrix(matrix);
	put_clues_in_matrix(matrix, clues);
}

/*
#include <stdio.h>
int main(void)
{
    int clues[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 4, 2, 2};
    int matrix[6][6];
    int row, col;

    build_matrix(matrix, clues);

    row = 0;
    while (row < 6)
    {
        col = 0;
        while (col < 6)
        {
            printf("%d ", matrix[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}
*/