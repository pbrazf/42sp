/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:07:14 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/25 15:10:52 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len_dest;
	int	i;

	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[len_dest] = src[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int main() {
        char str[20] = "abc";
        char str1[] = "def";
        char str2[] = "ghi";

        ft_strcat(str, str1);
        ft_strcat(str, str2);
        printf("%s\n", str); // abcdefghi
}
*/
