/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:29 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/23 16:11:12 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (!(str[counter] >= 32)
			&& str[counter] <= 126)
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
    char str1[] = "Texto 123 !";   // imprimível
    char str2[] = "Quebra\nLinha"; // contém \n (não imprimível)
    char str3[] = "";              // string vazia (deve retornar 1)

    if (ft_str_is_printable(str1))
        printf("str1 é válida\n");
    else
        printf("str1 NÃO é válida\n");

    if (ft_str_is_printable(str2))
        printf("str2 é válida\n");
    else
        printf("str2 NÃO é válida\n");

    if (ft_str_is_printable(str3))
        printf("str3 é válida\n");
    else
        printf("str3 NÃO é válida\n");

    return 0;
}
*/
