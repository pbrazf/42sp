/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:13:36 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/22 14:04:12 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

int main(void)
{
        int x = 20;
        int y = 6;
        int divisao;
        int resto;

        ft_div_mod(x, y, &divisao, &resto);
        printf("divisão = %d, resto = %d\n", divisao, resto);

        return 0;
}
*/
