/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:50:46 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/23 10:54:39 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	len_str;

	len_str = 0;
	while (*src != '\0')
	{
		dest[len_str] = *src;
		len_str++;
		src++;
	}
	dest[len_str] = '\0';
	return (dest);
}

/*
#include <stdio.h>
   
int main() {
    char str[] = "Ola";
    char *ptr_str1 = str;
    char str2[10];

    ft_strcpy(str2, ptr_str1);
    printf("%s", str2);
}
*/
