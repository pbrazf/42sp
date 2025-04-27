/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:09:27 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/23 15:27:43 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (!(str[counter] >= 97
				&& str[counter] <= 122))
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
    char str[] = "teste";
    char str2[] = "tesTe234";

    if (ft_str_is_lowercase(str))
        printf("str é válida\n");
    else
        printf("str NÃO é válida\n");

    if (ft_str_is_lowercase(str2))
        printf("str2 é válida\n");
    else
        printf("str2 NÃO é válida\n");

    return 0;
}
*/
