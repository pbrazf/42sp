#include "rush-02.h"

// Verifica se um bloco de até 3 dígitos é composto apenas por zeros
int	is_zero_block(char *block)
{
	int i = 0;

	while (block[i])
	{
		// Se encontrar qualquer caractere diferente de '0', retorna falso (0)
		if (block[i] != '0')
			return (0);
		i++;
	}
	// Se todos os caracteres forem '0', retorna verdadeiro (1)
	return (1);
}

// Compara duas strings numéricas, ignorando zeros à esquerda
int	compare_nbr_str(char *a, char *b)
{
	int	i;
	int	j;

	// Remove zeros à esquerda da primeira string
	while (*a == '0')
		a++;
	// Remove zeros à esquerda da segunda string
	while (*b == '0')
		b++;

	// Compara os tamanhos das strings após remoção dos zeros
	i = 0;
	while (a[i])
		i++;
	j = 0;
	while (b[j])
		j++;
	if (i != j)
		return (0); // Se os tamanhos forem diferentes, já são diferentes

	// Compara caractere por caractere
	i = 0;
	while (a[i])
	{
		if (a[i] != b[i])
			return (0);
		i++;
	}
	return (1); // Se tudo passou, são iguais
}

// Busca uma chave (key) na lista (dicionário) e retorna o valor correspondente
char	*find_in_dict(char *key, t_list *list)
{
	int	i = 0;

	// Percorre a lista até encontrar a chave ou chegar ao fim
	while (list[i].nbr)
	{
		// Compara a chave atual com a chave buscada
		if (compare_nbr_str(list[i].nbr, key))
			return (list[i].number_name); // Retorna o nome correspondente
		i++;
	}
	return (NULL); // Se não encontrou, retorna NULL
}

// Função intermediária que decide como imprimir um bloco não encontrado diretamente no dicionário
void	print_number_block(char *block, t_list *list, int *first)
{
	int	len;

	len = ft_strlen(block);

	// Se o bloco tem 3 dígitos e o primeiro não é zero, imprime como "centena"
	if (len == 3 && block[0] != '0')
		print_hundred_block(block, list, first);

	// Se o bloco tem 2 dígitos (ex: "21"), trata como "vinte e um"
	else if (len == 2)
		print_tens_block(block, list, first);

	// Se o bloco tem 1 dígito e não é zero, imprime diretamente
	else if (len == 1 && block[0] != '0')
	{
		if (*first == 0)
			write(1, " ", 1);
		ft_putstr(find_in_dict(block, list));
		*first = 0;
	}
}

// Imprime um bloco de até 3 dígitos (por exemplo, "123", "007")
void	print_block(char *block, t_list *list, int *first)
{
	char	*found = find_in_dict(block, list);

	// Se o bloco for encontrado diretamente no dicionário
	if (found)
	{
		if (*first == 0)
			write(1, " ", 1); // Adiciona espaço se já imprimimos algo antes
		ft_putstr(found);
		*first = 0; // Marca que já houve uma impressão
	}
	else
		// Se não encontrou diretamente, tenta quebrar o número e imprimir parte por parte
		print_number_block(block, list, first);
}

// Função principal de impressão: transforma o número em palavras por blocos de 3 dígitos
void	ft_print_big(char *nbr_str, t_list *list, int *first)
{
	int		len;
	int		block_index;
	int		total_blocks;
	char	block[4];
	char	*power_names[] = {
		"", "thousand", "million", "billion", "trillion",
		"quadrillion", "quintillion", "sextillion", "septillion",
		"octillion", "nonillion", "decillion", "undecillion"
	};

	// Calcula o comprimento total da string do número
	len = ft_strlen(nbr_str);

	// Divide o número em blocos de 3 dígitos (ex: 1.234.567 → 3 blocos)
	total_blocks = (len + 2) / 3;

	block_index = 0;
	while (block_index < total_blocks)
	{
		// Extrai o bloco atual (ex: "123")
		extract_block(nbr_str, block, block_index, len);

		// Só imprime se o bloco não for composto apenas por zeros
		if (!is_zero_block(block))
		{
			// Caso especial: primeiro bloco é exatamente "100"
			if (block_index == 0 && ft_strlen(block) == 3 && block[0] == '1')
			{
				if (*first == 0)
					write(1, " ", 1);
				ft_putstr(find_in_dict("1", list));
				write(1, " ", 1);
				ft_putstr(find_in_dict("100", list));
				*first = 0;
			}
			else
			{
				// Imprime o bloco (ex: "one hundred twenty-three")
				print_block(block, list, first);

				// Se o bloco representa uma potência (mil, milhão...), imprime ela
				if (power_names[total_blocks - block_index - 1][0] != '\0')
				{
					if (*first == 0)
						write(1, " ", 1);
					ft_putstr(power_names[total_blocks - block_index - 1]);
				}
			}
		}
		block_index++;
	}
}
