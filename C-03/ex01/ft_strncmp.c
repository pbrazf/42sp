/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:27:56 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/29 09:24:21 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}

int main() {
        char str[] = "teste";
        char str1[] = "tesTE";

        int comp3 = ft_strncmp(str, str1, 3);
        // int comp5 = ft_strncmp(str, str1, 5);

        printf("%d\n", comp3);
        // printf("%d\n", comp5);
}

