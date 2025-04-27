/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <gcruz-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:33:52 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/27 14:59:20 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// The main function first checks the input arguments 
// to validate if there's only 2 arguments and if correct, then
// validates the input by calling the validate_input function.
// Then, it builds the game matrix by calling the build_matrix 
// and goes to the condition where the solution of the game is.
// If the function solve_matrix function manages to resolve the puzzle 
// it prints the solution. Or return error in case of failure.
// - matrix: a 6x6 matrix where the game will be represented, including
// the clues around the grid.
// - clues: an array to store the 16 clues provided in the input.
// - row, col: indexes used to iterate through the matrix to print it.
int	main(int argc, char **argv)
{
	int	matrix[6][6];
	int	clues[16];

	if (argc == 2)
	{
		if (!validate_input(argv[1], clues))
			return (0);
		build_matrix(matrix, clues);		
		if (solve_matrix(matrix, 1, 1))
			print_matrix(matrix);
		else
			ft_error();
	}
	else
	{
		ft_error();
	}
	return (0);
}
