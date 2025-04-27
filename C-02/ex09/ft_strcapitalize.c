/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:26:29 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 10:57:21 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		counter;
	int		new_word;

	counter = 0;
	new_word = 1;
	while (str[counter] != '\0')
	{
		if (new_word && str[counter] >= 'a' && str[counter] <= 'z')
			str[counter] -= 32;
		else if (!new_word && str[counter] >= 'A' && str[counter] <= 'Z')
			str[counter] += 32;
		if ((str[counter] >= '0' && str[counter] <= '9')
			|| (str[counter] >= 'A' && str[counter] <= 'Z')
			|| (str[counter] >= 'a' && str[counter] <= 'z'))
			new_word = 0;
		else
			new_word = 1;
		counter++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "oi, tudo bem? 42palavras quarenta-e-duas; cinquenta+e+um";
	char	str2[] = "TUDO MAIUSCULO!";
	char	str3[] = "já estava minusculo";

	printf("%s\n", ft_strcapitalize(str));
	printf("%s\n", ft_strcapitalize(str2));
	printf("%s\n", ft_strcapitalize(str3));
	return (0);
}
*/
