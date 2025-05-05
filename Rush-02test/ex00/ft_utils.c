/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:32:46 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:32:48 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

// Checks if the input string contains only numeric characters
int	is_numeric_string(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

// Checks if the input number's length is supported by the dictionary
int	dict_supports_input(char *nbr_str, t_list *list)
{
	int		i;
	int		max_len;
	int		nbr_len;
	int		len;

	i = 0;
	max_len = 0;
	nbr_len = ft_strlen(nbr_str);
	while (list[i].nbr)
	{
		len = ft_strlen(list[i].nbr);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (nbr_len <= max_len);
}

// Duplicates a string by allocating new memory and copying characters
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		lenght;

	lenght = 0;
	while (src[lenght])
		lenght++;
	dest = (char *)malloc(sizeof(char) * (lenght + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Prints a string character by character using write
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// Returns the length of a string (number of characters before '\0')
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
