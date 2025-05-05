#include "rush-02.h"

// Lê do arquivo até capturar os dígitos que representam o número (chave) no dicionário.
// Exemplo: em "42 : forty two", extrai o "42" para o buffer `dest`.
void	get_nbr(int file, char *dest)
{
	int		i;
	char	buffer[1];

	// Lê o primeiro caractere do arquivo
	read(file, buffer, 1);

	// Ignora quebras de linha no início da leitura (linhas vazias)
	while (buffer[0] == '\n')
		read(file, buffer, 1);

	i = 0;
	// Enquanto o caractere for um dígito (entre '0' e '9'), salva em `dest`
	while (buffer[0] >= '0' && buffer[0] <= '9')
	{
		dest[i] = buffer[0];

		// Avança para o próximo caractere
		read(file, buffer, 1);
		i++;
	}

	// Finaliza a string com '\0'
	dest[i] = '\0';
}


// Lê do arquivo até o final da linha, salvando o nome correspondente ao número.
// Exemplo: em "42 : forty two", extrai o "forty two" para o buffer `dest`.
void	get_number_name(int file, char *buffer, char *dest)
{
	int	i;

	i = 0;
	// Enquanto o caractere atual não for uma quebra de linha
	while (buffer[0] != '\n')
	{
		// Copia o caractere atual para o buffer de destino
		dest[i] = buffer[0];

		// Avança para o próximo caractere do arquivo
		read(file, buffer, 1);
		i++;
	}

	// Finaliza a string com '\0'
	dest[i] = '\0';
}


// Cria uma lista com todos os chave:valor do arquivo .dict que temos de base.
t_list	*create_list(char *file_name)
{
	int		i;
	int		file;
	char	buffer[1];
	t_list	*list;
	char	tmp_nbr[128];
	char	tmp_name[128];

	file = open(file_name, O_RDONLY); // Abre o arquivo .dict
	// Inicializa a variavel list do tipo t_list alocando a memoria com base no DICT_SIZE hardcoded (42)
	list = (t_list *)malloc(sizeof(t_list) * (DICT_SIZE + 1)); // COLOCAMOS +1 PARA ALOCAR O NULL NO FINAL.
	if (file == -1 || list == NULL)
		return (NULL);

	i = 0;
	// Percorre as linhas 
	while (i < DICT_SIZE)
	{	
		// Exemplo de linha: 60: sixty
		// Pega o numero (60) e ALOCA em tmp_nbr
		get_nbr(file, tmp_nbr);

		// Após pegar o numero, passa possíveis espaços e ":"
		read(file, buffer, 1);
		while (buffer[0] == ' ')
			read(file, buffer, 1);
		if (buffer[0] == ':')
			read(file, buffer, 1);
		while (buffer[0] == ' ')
			read(file, buffer, 1);
		
		// Passou o ":" e possíveis espaços, pega o número escrito
		// (sixty) e salva em tmp_name
		get_number_name(file, buffer, tmp_name);

		// Usamos ft_strdup para alocar os resultados em tmp em um local na memória.
		// Por final, atribuimos os resultados encontrados (agora alocador na memoria)
		// na list, dentro da struct onde:
		// nbr: '60'
		// number_name: 'sixty'
		list[i].nbr = ft_strdup(tmp_nbr);
		list[i].number_name = ft_strdup(tmp_name);

		// Passa para o próximo indice e continua a rodar pelo .dict
		i++;
	}

	// Adiciona ao ultimo item da lista, NULOS
	list[i].nbr = NULL;
	list[i].number_name = NULL;

	// Fecha o arquivo .dict que estava aberto 
	close(file);
	return (list);
}

// Função para liberar a lista alocada na memória 
void	free_list(t_list *list)
{
	int	i = 0;

	// Para de iterar quando o campo 'nbr' for NULL
	while (list[i].nbr != NULL)
	{
		if (list[i].nbr)
			free(list[i].nbr);
		if (list[i].number_name)
			free(list[i].number_name);
		i++;
	}
	free(list);
}