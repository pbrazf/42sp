/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:37:06 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/23 14:23:31 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if (!((str[counter] >= 65 && str[counter] <= 90)
				|| (str[counter] >= 97 && str[counter] <= 122)))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void) {
    char str[] = "teStE soment3 caracteres";
    char str2[] = "teste";

    if (ft_str_is_alpha(str))
        printf("str é válida\n");
    else
        printf("str NÃO é válida\n");

    if (ft_str_is_alpha(str2))
        printf("str2 é válida\n");
    else
        printf("str2 NÃO é válida\n");

    return 0;
}
*/
