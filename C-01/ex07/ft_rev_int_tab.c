/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:28:21 by pedrferr          #+#    #+#             */
/*   Updated: 2025/04/22 12:24:38 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp_value;

	i = 0;
	while (i < (size - 1) / 2)
	{
		temp_value = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp_value;
		i++;
	}
}

/*
int main(void) {
    int test[4] = {2, 4, 5, 10};
    int qtd = 4; 
    
    ft_rev_int_tab(test, qtd);

    // Mostrar resultado
    for (int i = 0; i < qtd; i++) {
        printf("%d ", test[i]);
    }

    return 0;
}
*/
