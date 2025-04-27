/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <gcruz-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:07:28 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/27 15:31:43 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <stdio.h>
#include "header.h"

// Calculates and returns the length of a string.
// - str: the input string to measure.
// - i: counter used to iterate through the string
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// Parses the input string into the clues array.
// Accepts only digits '1' to '4' separated by spaces.
// - str: input string from the command line.
// - clues: integer array to store the parsed numbers.
// - i: index for traversing the input string.
// - j: index for filling the clues array.
int	*parse_to_numbers(char *str, int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4' && j < 16)
		{
			clues[j] = str[i] - '0';
			j++;
		}
		else if (str[i] != ' ')
		{
			return (0);
		}
		i++;
	}
	return (clues);
}

// Counts how many times the number 4 appears in the clues array.
// - numbers: the clues array.
// - i: counter used to traverse the array.
// - count: counter for number of '4' found.
int	count_number_four(int *numbers)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < 16)
	{
		if (numbers[i] == 4)
		{
			count++;
		}
	i++;
	}
	return (count);
}

// Checks if the sum for opposites sides(top+bottom, left+right) 
// is a valid sum(must be <= 5).
// - the first loop being the columns
// - and the second loop being the lines
// - i: index to iterate through the top-bottom and left-right clues.
int	check_sum_of_pairs(int *numbers)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (numbers[i] + numbers[i + 4] > 5)
			return (0);
		i++;
	}
	i = 8;
	while (i < 12)
	{
		if (numbers[i] + numbers[i + 4] > 5)
			return (0);
		i++;
	}
	return (1);
}

// Validates the input received from the command line.
// Checks the string length, the format of numbers and spaces, 
// ensures 16 clues were given, and basic rules about clues are respected.
// Variables:
// - str: input string received from the command line.
// - clues: array where the parsed clues will be stored.
int	*validate_input(char *str, int *clues)
{
	if (ft_strlen(str) != 31)
	{
		ft_error();
		return (0);
	}
	if (!parse_to_numbers(str, clues))
	{
		ft_error();
		return (0);
	}
	if (count_number_four(clues) == 3 || count_number_four(clues) >= 5)
	{
		ft_error();
		return (0);
	}
	if (!check_sum_of_pairs(clues))
	{
		ft_error();
		return (0);
	}
	return (clues);
}
