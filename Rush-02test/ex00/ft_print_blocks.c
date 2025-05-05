/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_blocks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:32:10 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:32:12 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

// Prints the hundreds part of a 3-digit block 
// (e.g., "345" prints "three hundred")
void	print_hundred_block(char *block, t_context *ctx)
{
	char	hundred[2];
	char	*hundred_word;
	char	rest[3];

	hundred[0] = block[0];
	hundred[1] = '\0';
	hundred_word = find_in_dict(hundred, ctx->list);
	if (ctx->first == 0)
		write(1, " ", 1);
	ft_putstr(hundred_word);
	write(1, " ", 1);
	ft_putstr("hundred");
	ctx->first = 0;
	rest[0] = block[1];
	rest[1] = block[2];
	rest[2] = '\0';
	if (!is_zero_block(rest))
		print_number_block(rest, ctx);
}

// Prints tens and units separately when a 2-digit number like
// "42" is not found in the dictionary
void	print_split_tens(char *block, t_context *ctx)
{
	char	tens[3];
	char	units[2];

	tens[0] = block[0];
	tens[1] = '0';
	tens[2] = '\0';
	units[0] = block[1];
	units[1] = '\0';
	if (ctx->first == 0)
		write(1, " ", 1);
	ft_putstr(find_in_dict(tens, ctx->list));
	if (block[1] != '0')
	{
		write(1, " ", 1);
		ft_putstr(find_in_dict(units, ctx->list));
	}
	ctx->first = 0;
}

// Prints a 2-digit number using the dictionary or splits it
// into tens and units
void	print_tens_block(char *block, t_context *ctx)
{
	char	*found;

	found = find_in_dict(block, ctx->list);
	if (found)
	{
		if (ctx->first == 0)
			write(1, " ", 1);
		ft_putstr(found);
		ctx->first = 0;
	}
	else
		print_split_tens(block, ctx);
}

// Decides how to print a block that is not directly found in the dictionary
void	print_number_block(char *block, t_context *ctx)
{
	int	len;

	len = ft_strlen(block);
	if (len == 3 && block[0] != '0')
		print_hundred_block(block, ctx);
	else if (len == 2)
		print_tens_block(block, ctx);
	else if (len == 1 && block[0] != '0')
	{
		if (ctx->first == 0)
			write(1, " ", 1);
		ft_putstr(find_in_dict(block, ctx->list));
		ctx->first = 0;
	}
}

// Prints a block of up to 3 digits (e.g., "123", "007")
void	print_block(char *block, t_context *ctx)
{
	char	*found;

	found = find_in_dict(block, ctx->list);
	if (found)
	{
		if (ctx->first == 0)
			write(1, " ", 1);
		ft_putstr(found);
		ctx->first = 0;
	}
	else
		print_number_block(block, ctx);
}
