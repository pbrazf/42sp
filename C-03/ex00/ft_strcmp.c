/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:15:35 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 17:22:27 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>

int main() {
        char str[] = "Teste";
        char str1[] = "teste";
        char str2[] = "Teste";
        int             result;
        int             result1;
        int             result2;

        result = ft_strcmp(str, str1);
        printf("%s <> %s = %i\n", str, str1, result);

        result1 = ft_strcmp(str, str2);
        printf("%s <> %s = %i\n", str, str2, result1);

        result2 = ft_strcmp(str, str1);
        printf("%s <> %s = %i\n", str1, str2, result2);
}
*/
