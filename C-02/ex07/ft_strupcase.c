/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:13:10 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 13:41:01 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] >= 'a' && str[counter] <= 'z')
		{
			str[counter] = str[counter] - 32;
		}
		counter++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "teste Teste 123";
	char	str2[] = "tudo minusculo!";
	char	str3[] = "JÁ ESTAVA MAIUSCULO";

	printf("%s\n", ft_strupcase(str));
	printf("%s\n", ft_strupcase(str2));
	printf("%s\n", ft_strupcase(str3));
	return (0);
}
*/
