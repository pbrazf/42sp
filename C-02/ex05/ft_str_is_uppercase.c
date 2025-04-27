/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:34:13 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 13:59:35 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (!(str[counter] >= 65
				&& str[counter] <= 90))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
    char str[] = "teSTE";
    char str2[] = "TESTE";

    if (ft_str_is_uppercase(str))
        printf("str é válida\n");
    else
        printf("str NÃO é válida\n");

    if (ft_str_is_uppercase(str2))
        printf("str2 é válida\n");
    else
        printf("str2 NÃO é válida\n");

    return 0;
}
*/
