/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:48:01 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 13:59:01 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (!(str[counter] >= 48
				&& str[counter] <= 57))
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
    char str[] = "1234";
    char str2[] = "teste2";

    if (ft_str_is_numeric(str))
        printf("str é válida\n");
    else
        printf("str NÃO é válida\n");

    if (ft_str_is_numeric(str2))
        printf("str2 é válida\n");
    else
        printf("str2 NÃO é válida\n");

    return 0;
	}
*/
