/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:32:55 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:32:57 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

// Parses command-line arguments to determine dictionary 
// and number to convert
int	parse_args(int argc, char **argv, char **dict, char **num)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		*dict = "numbers.dict";
	else
		*dict = argv[1];
	if (argc == 2)
		*num = argv[1];
	else
		*num = argv[2];
	return (1);
}

// Main function: validates input, loads dictionary, and prints 
// the number in words
int	main(int argc, char **argv)
{
	t_list		*list;
	t_context	ctx;
	char		*num;
	char		*dict;

	if (!parse_args(argc, argv, &dict, &num))
		return (0);
	if (!is_numeric_string(num))
		return (write(1, "Error\n", 6), 0);
	if (*num == '0' && num[1] == '\0')
		return (write(1, "zero\n", 5), 0);
	list = create_list(dict);
	if (!list)
		return (write(1, "Dict Error\n", 11), 0);
	if (!dict_supports_input(num, list))
		return (write(1, "Dict Error\n", 11), free_list(list), 0);
	ctx.list = list;
	ctx.first = 1;
	ft_print_big(num, &ctx);
	write(1, "\n", 1);
	free_list(list);
	return (0);
}
