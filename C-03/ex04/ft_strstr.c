/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:27:20 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/29 09:46:23 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "42sp é muito legal";
	char	str1[] = "muito";
	char	str2[] = "chato";
	char	*vazia = "";

	// Teste 1: Encontrar substring existente
	printf("%s\n", ft_strstr(str, str1)); // Esperado: "muito legal"

	// Teste 2: Substring não existente
	printf("%s\n", ft_strstr(str, str2)); // Esperado: (null)

	// Teste 3: Substring vazia
	printf("%s\n", ft_strstr(str, vazia)); // Esperado: "42sp é muito legal"

	return (0);
}
*/
