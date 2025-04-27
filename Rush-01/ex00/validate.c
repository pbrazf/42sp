/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcruz-pe <gcruz-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:07:28 by gcruz-pe          #+#    #+#             */
/*   Updated: 2025/04/27 10:57:59 by gcruz-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> 
#include <malloc.h> 
#include <stdio.h>
#include "header.h"

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
			clues[j]= str[i] - '0';
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

	// int i;
	// i = 0;
	// while (i < 16)
	// {
	// 	printf("clues[%d] = %d\n", i, clues[i]);
	// 	i++;
	// }