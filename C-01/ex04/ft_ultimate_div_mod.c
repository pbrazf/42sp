/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:04:52 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/22 12:21:26 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;

	temp_a = *a;
	*a = *a / *b;
	*b = temp_a % *b;
}

/*
#include <stdio.h>

int main(void)
{
        int x = 20;
        int y = 6;

        ft_ultimate_div_mod(&x, &y);
        printf("divisão = %d, resto = %d\n", x, y);

        return 0;
}
*/
