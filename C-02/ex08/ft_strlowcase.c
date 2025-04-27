/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:15:48 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 10:17:10 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] >= 'A' && str[counter] <= 'Z')
		{
			str[counter] = str[counter] + 32;
		}
		counter++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "TESTE Teste 123";
	char	str2[] = "TUDO MAIUSCULO!";
	char	str3[] = "já estava minusculo";

	printf("%s\n", ft_strlowcase(str));
	printf("%s\n", ft_strlowcase(str2));
	printf("%s\n", ft_strlowcase(str3));
	return (0);
}
*/
