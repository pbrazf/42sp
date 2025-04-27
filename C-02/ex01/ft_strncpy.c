/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:50:46 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/24 13:40:28 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	len_str;

	len_str = 0;
	while (len_str < n && src[len_str] != '\0')
	{
		dest[len_str] = src[len_str];
		len_str++;
	}
	while (len_str < n)
	{	
		dest[len_str] = '\0';
		len_str++;
	}
	return (dest);
}

/*
#include <stdio.h>
   
int main() {
    char str[] = "Ola, tudo bem?";
    char *ptr_str1 = str;
    char str2[15];

    ft_strncpy(str2, ptr_str1, 5);
    printf("%s", str2);
}
*/
