#include "rush-02.h"

int	main(int argc, char **argv)
{
	t_list *list;
	int first;
	char *num;
	char *dict;

	// Se tem exatamente 2 argumentos
	if (argc < 2 || argc > 3)
	{
		write(1, "error\n", 6);
		return (0);
	}

	// Definição de número e do .dict
	dict = (argc == 2) ? "numbers.dict" : argv[1];
	num = (argc == 2) ? argv[1] : argv[2];

	// flag para identificar a primeira vez que o numero foi printado
	first = 1;

	// Se o parametro passado é um numero negativo ou invalido, retorna erro
	if (!is_numeric_string(num))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	// Verifica se o número é 0 (único caso que quebraria a lógica)
	if (*num == '0' && num[1] == '\0')
	{
		write(1, "zero\n", 5);
		return (0);
	}
	// cria lista chave:valor com base no dicionario
	list = create_list(dict);
	if (!list || !dict_supports_input(num, list))
	{
		write(1, "Dict Error\n", 11);
		if (list)
			free_list(list);
		return (0);
	}
	// printa o numero recebido como argumento com base na lista que temos 
	ft_print_big(num, list, &first);
	write(1, "\n", 1);
	// Limpa a memória alocada em list
	free_list(list);

	return (0);
}


// int i = 0;
// while (list[i].nbr)
// {
// 	write(1, "[", 1);
// 	ft_putstr(list[i].nbr);
// 	write(1, "] -> ", 5);
// 	ft_putstr(list[i].number_name);
// 	write(1, "\n", 1);
// 	i++;
// }
