#include "rush-02.h"

// Função para verificar se argumento de entrada é válido
int is_numeric_string(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int	dict_supports_input(char *nbr_str, t_list *list)
{
	int		i = 0;
	int		max_len = 0;
	int		nbr_len;

	nbr_len = ft_strlen(nbr_str);

	while (list[i].nbr)
	{
		int len = ft_strlen(list[i].nbr);
		if (len > max_len)
			max_len = len;
		i++;
	}
	return (nbr_len <= max_len);
}

// Duplicação de string:
// Recebe uma string `src` e retorna uma nova cópia alocada dinamicamente com malloc.
char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		lenght;

	lenght = 0;
	// Calcula o tamanho da string `src` (sem contar o '\0')
	while (src[lenght])
		lenght++;

	// Aloca memória para a nova string (`dest`) com tamanho +1 para o '\0'
	dest = (char *) malloc(sizeof(char) * (lenght + 1));

	// Se ocorrer falha na alocação, retorna NULL
	if (dest == NULL)
		return (NULL);
	
	i = 0;
	// Copia caractere por caractere de `src` para `dest`
	while (i < lenght)
	{
		dest[i] = src[i];
		i++;
	}
	// Finaliza a nova string com o caractere nulo
	dest[i] = '\0';
	return (dest);
}

// Impressão de string:
// Recebe uma string `str` e imprime todos os seus caracteres usando write().
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

// Calcula o comprimento de uma string:
// Retorna a quantidade de caracteres até o caractere nulo '\0'
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}