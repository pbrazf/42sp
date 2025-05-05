/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_core.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:32:19 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:32:23 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

// Checks if a block of up to 3 digits contains only zeros
int	is_zero_block(char *block)
{
	int	i;

	i = 0;
	while (block[i])
	{
		if (block[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

// Prints a block followed by its power (if applicable)
void	print_block_w_power(char *block, char *power, t_context *ctx)
{
	print_block(block, ctx);
	if (power[0] != '\0')
	{
		if (ctx->first == 0)
			write(1, " ", 1);
		ft_putstr(power);
	}
}

// Fills an array with power-of-thousand names such as "thousand", "million"
// , etc.
void	get_power_names(char **power_names)
{
	power_names[0] = "";
	power_names[1] = "thousand";
	power_names[2] = "million";
	power_names[3] = "billion";
	power_names[4] = "trillion";
	power_names[5] = "quadrillion";
	power_names[6] = "quintillion";
	power_names[7] = "sextillion";
	power_names[8] = "septillion";
	power_names[9] = "octillion";
	power_names[10] = "nonillion";
	power_names[11] = "decillion";
	power_names[12] = "undecillion";
}

// Handles printing of a single block and its power name,
// including special "100" case
void	handle_block(char *block, int i, int total, t_context *ctx)
{
	char	*power;
	int		is_one_hundred;
	char	*power_names[13];

	get_power_names(power_names);
	power = power_names[total - i - 1];
			is_one_hundred = (ft_strlen(block) == 3
			&& block[0] == '1' && block[1] == '0' && block[2] == '0');
	if (is_one_hundred)
	{
		if (ctx->first == 0)
			write(1, " ", 1);
		ft_putstr("one hundred");
		if (power[0] != '\0')
		{
			write(1, " ", 1);
			ft_putstr(power);
		}
		ctx->first = 0;
	}
	else
		print_block_w_power(block, power, ctx);
}

// Main function to convert and print a number in words, by 3-digit blocks
void	ft_print_big(char *nbr_str, t_context *ctx)
{
	int		len;
	int		block_index;
	int		total_blocks;
	char	block[4];

	len = ft_strlen(nbr_str);
	total_blocks = (len + 2) / 3;
	block_index = 0;
	while (block_index < total_blocks)
	{
		extract_block(nbr_str, block, block_index, len);
		if (!is_zero_block(block))
			handle_block(block, block_index, total_blocks, ctx);
		block_index++;
	}
}
