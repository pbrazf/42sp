/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:32:28 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:32:30 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

// Compares two numeric strings ignoring leading zeros
int	compare_nbr_str(char *a, char *b)
{
	int	i;
	int	j;

	while (*a == '0')
		a++;
	while (*b == '0')
		b++;
	i = 0;
	while (a[i])
		i++;
	j = 0;
	while (b[j])
		j++;
	if (i != j)
		return (0);
	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1);
}

// Finds a key in the dictionary list and returns its corresponding word
char	*find_in_dict(char *key, t_list *list)
{
	int	i;

	i = 0;
	while (list[i].nbr)
	{
		if (compare_nbr_str(list[i].nbr, key))
			return (list[i].number_name);
		i++;
	}
	return (NULL);
}

// Extracts a group of up to 3 digits from the full number string,
// based on its block index
void	extract_block(char *nbr_str, char *block, int block_index, int len)
{
	int	block_start;
	int	block_len;
	int	i;

	if (len % 3 != 0 && block_index == 0)
		block_len = len % 3;
	else
		block_len = 3;
	if (block_index == 0)
		block_start = 0;
	else
	{
		if (len % 3 != 0)
			block_start = (len % 3 + (block_index - 1) * 3);
		else
			block_start = (block_index * 3);
	}
	i = 0;
	while (i < block_len && nbr_str[block_start + i])
	{
		block[i] = nbr_str[block_start + i];
		i++;
	}
	block[i] = '\0';
}
