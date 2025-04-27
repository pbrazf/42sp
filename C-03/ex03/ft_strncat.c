/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:20:20 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/25 15:23:21 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len_dest;
	unsigned int	i;

	len_dest = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	i = 0;
	while (i < nb && src[i] != '\0')
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

int	main(void)
{
	char	str[20] = "abc";
	char	str1[] = "defgh"
	char	str2[] = "ijkl"; 

	// Concatena no máximo 3 caracteres de str1 em str
	ft_strncat(str, str1, 3);
	printf("%s\n", str); 

	// Concatena no máximo 2 caracteres de str2 em str
	ft_strncat(str, str2, 2);
	printf("%s\n", str);

	return (0);
}
*/
