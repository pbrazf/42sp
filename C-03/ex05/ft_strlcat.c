/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:12:48 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/29 10:08:39 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_of_src;
	unsigned int	size_of_dest;
	unsigned int	i;
	unsigned int	dest_len;

	size_of_src = ft_strlen(src);
	size_of_dest = ft_strlen(dest);
	dest_len = size_of_dest;
	if (size <= size_of_dest)
		return (size + size_of_src);
	i = 0;
	while (dest_len < size - 1 && src[i] != '\0')
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (size_of_dest + size_of_src);
}

/*
#include <stdio.h>

int	main(void)
{
	unsigned int	sum;
	char			str[] = "string de testes";
	char			dest[30] = "string inicio, ";

	printf("%s\n", dest);
	sum = ft_strlcat(dest, str, 20);
	printf("%s\n", dest);
	printf("retorno: %i\n", sum);
	printf("len_dest: %i\n", ft_strlen(dest));
}
*/
