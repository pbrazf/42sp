/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:23:40 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/26 18:33:10 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Header starts

#ifndef HEADER_H
#define HEADER_H

// Include the libraries that all files will use

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//define all the prototypes used in this program to be called in other functions

void	ft_putchar(char c);
void	ft_error(void);
void	ft_string(char *str);
void	build_matrix(int matrix[6][6], int *clues);
int	*validate_input(char *str, int *clues);
int	solve_matrix(int matrix[6][6], int row, int col);

//Ends the header
#endif
