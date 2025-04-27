/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <gcruz-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:23:40 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/27 15:32:05 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header starts
#ifndef HEADER_H
# define HEADER_H

// Include the libraries that all files will use
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//define all the prototypes used in this program to be called in other functions

void	ft_putchar(char c);
void	ft_error(void);
void	build_matrix(int matrix[6][6], int *clues);
int		*validate_input(char *str, int *clues);
int		solve_matrix(int matrix[6][6], int row, int col);
void	print_matrix(int matrix[6][6]);
int		count_visible_from_top(int matrix[6][6], int col);
int		count_visible_from_bottom(int matrix[6][6], int col);
int		count_visible_from_left(int matrix[6][6], int row);
int		count_visible_from_right(int matrix[6][6], int row);
int		check_clues(int matrix[6][6]);
int		is_valid(int matrix[6][6], int row, int col, int num);
int		is_row_complete(int matrix[6][6], int row);
int		is_col_complete(int matrix[6][6], int col);
int		check_row_constraints(int matrix[6][6], int row);
int		check_col_constraints(int matrix[6][6], int col);

//Ends the header
#endif
