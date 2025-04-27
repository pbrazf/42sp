/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:45:36 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/26 18:49:09 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//Error Message
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &str, 1);
	}
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

/*
// This function receives a pointer to a string(an array of chars).
// A counter is declared to be used as an index in the loop
// with the purpose to print each letter from a string.
// The '\0' char is the end of a string in C.
// The loop continues as long it doesn't find a null char(\0)
// The middle parameter in the write function is the address
// from the actual char of the string
void	ft_string(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
}

// This function is used to print an error message to the user
// It starts with the declaration of a pointer error with type char
// and it is assigned an error message to this variable error
// The function ft_string it's called and it begins
// the iteration to each position of the array
// Iteration 1: str[0] = 'I';
void	ft_error(void)
{
	char	*error;

	error = "Error!\n";
	ft_string(error);
}
*/
