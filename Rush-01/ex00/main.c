/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:33:52 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/26 19:27:10 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_full_matrix(int matrix[6][6])
{
	int	row;
	int	col;

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
}

void	print_matrix(int matrix[6][6])
{
	int	row;
	int	col;

	row = 1;
	while (row < 5)
	{
		col = 1;
		while (col < 5)
		{
			printf("%d ", matrix[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

int	main(int argc, char **argv)
{
	int	matrix[6][6];
	int	clues[16];

	if (argc == 2)
	{
		if (!validate_input(argv[1], clues))
			return (0);
		build_matrix(matrix, clues);
		// print_full_matrix(matrix);
		printf("\n");
		
		if (solve_matrix(matrix, 1, 1))
			print_matrix(matrix); // Sucesso, matriz preenchida corretamente
		else
			ft_error(); // Não conseguiu resolver
	}
	else
	{
		ft_error();
	}
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int	matrix[6][6];
	int	clues[16];

	if (argc == 2)
	{
		if (!validate_input(argv[1], clues))
		{
			return (0);
		}
		else
		{
			build_matrix(matrix, clues);
			print_matrix(matrix);
		}
	else
	{
		ft_error();
	}
	return (0);
	}
}
*/
