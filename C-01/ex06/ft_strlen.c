/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:03:41 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/22 12:24:11 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	str_len;

	str_len = 0;
	while (*str != '\0')
	{
		str_len += 1;
		str += 1;
	}
	return (str_len);
}

/*
#include <stdio.h>

int main(void)
{
        char texto[] = "42 São Paulo";

        int tamanho = ft_strlen(texto);

        printf("Tamanho: %d\n", tamanho);

        return 0;
}
*/
