#include "rush-02.h"

// Imprime a parte da centena de um bloco de 3 dígitos
void	print_hundred_block(char *block, t_list *list, int *first)
{
	char	hundred[2];
	char	*hundred_word;
	char	rest[3];

	// Extrai o primeiro dígito e finaliza a string com '\0'
	hundred[0] = block[0];
	hundred[1] = '\0';

	// Busca o nome correspondente no dicionário
	hundred_word = find_in_dict(hundred, list);

	// Imprime espaço antes, se necessário
	if (*first == 0)
		write(1, " ", 1);

	// Imprime o número + "hundred"
	ft_putstr(hundred_word);
	write(1, " ", 1);
	ft_putstr("hundred");

	*first = 0;

	// Pega os dois dígitos restantes
	rest[0] = block[1];
	rest[1] = block[2];
	rest[2] = '\0';

	// Se o restante não for "00", imprime recursivamente
	if (!is_zero_block(rest))
		print_number_block(rest, list, first);
}

// Imprime blocos de 2 dígitos, tratando casos como "21", "40", "05"
void	print_tens_block(char *block, t_list *list, int *first)
{
	char	*found;
	char	tens[3];
	char	units[2];

	// Busca diretamente o valor completo no dicionário (ex: "20", "11", etc.)
	found = find_in_dict(block, list);
	if (found)
	{
		if (*first == 0)
			write(1, " ", 1);
		ft_putstr(found);
		*first = 0;
	}
	else
	{
		// Se não encontrou, separa o dígito da dezena
		tens[0] = block[0];
		tens[1] = '0';
		tens[2] = '\0';

		// E o dígito da unidade
		units[0] = block[1];
		units[1] = '\0';

		if (*first == 0)
			write(1, " ", 1);

		// Imprime a dezena (ex: "40")
		ft_putstr(find_in_dict(tens, list));

		// Se a unidade não for zero, imprime também (ex: "3")
		if (block[1] != '0')
		{
			write(1, " ", 1);
			ft_putstr(find_in_dict(units, list));
		}
		*first = 0;
	}
}

// Extrai um bloco de até 3 dígitos da string do número principal
void	extract_block(char *nbr_str, char *block, int block_index, int len)
{
	int	block_start;
	int	block_len;
	int	i;

	// Define o tamanho do bloco com base na posição
	if (len % 3 != 0 && block_index == 0)
		block_len = len % 3;
	else
		block_len = 3;

	// Define o ponto de início do bloco na string original
	if (block_index == 0)
		block_start = 0;
	else
		block_start = (len % 3 != 0)
			? (len % 3 + (block_index - 1) * 3)
			: (block_index * 3);

	// Copia os caracteres do número original para o bloco
	i = 0;
	while (i < block_len && nbr_str[block_start + i])
	{
		block[i] = nbr_str[block_start + i];
		i++;
	}
	block[i] = '\0'; // Finaliza o bloco com '\0'
}
