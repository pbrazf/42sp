/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:31:55 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:32:02 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

// Reads digits from the file and stores them as a numeric key string
void	get_nbr(int file, char *dest)
{
	int		i;
	char	buffer[1];

	read(file, buffer, 1);
	while (buffer[0] == '\n')
		read(file, buffer, 1);
	i = 0;
	while (buffer[0] >= '0' && buffer[0] <= '9')
	{
		dest[i] = buffer[0];
		read(file, buffer, 1);
		i++;
	}
	dest[i] = '\0';
}

// Reads the word part of the dictionary entry and stores it in dest
void	get_number_name(int file, char *buffer, char *dest)
{
	int	i;

	i = 0;
	while (buffer[0] != '\n')
	{
		dest[i] = buffer[0];
		read(file, buffer, 1);
		i++;
	}
	dest[i] = '\0';
}

// Reads a single dictionary entry and fills a t_list item
void	fill_entry(int file, t_list *entry)
{
	char	buffer[1];
	char	tmp_nbr[128];
	char	tmp_name[128];

	get_nbr(file, tmp_nbr);
	read(file, buffer, 1);
	while (buffer[0] == ' ')
		read(file, buffer, 1);
	if (buffer[0] == ':')
		read(file, buffer, 1);
	while (buffer[0] == ' ')
		read(file, buffer, 1);
	get_number_name(file, buffer, tmp_name);
	entry->nbr = ft_strdup(tmp_nbr);
	entry->number_name = ft_strdup(tmp_name);
}

// Creates a list of key:value pairs from the dictionary file
t_list	*create_list(char *file_name)
{
	int		i;
	int		file;
	t_list	*list;

	file = open(file_name, O_RDONLY);
	list = (t_list *)malloc(sizeof(t_list) * (DICT_SIZE + 1));
	if (file == -1 || list == NULL)
		return (NULL);
	i = 0;
	while (i < DICT_SIZE)
	{
		fill_entry(file, &list[i]);
		i++;
	}
	list[i].nbr = NULL;
	list[i].number_name = NULL;
	close(file);
	return (list);
}

// Frees the memory used by the list of dictionary entries
void	free_list(t_list *list)
{
	int	i;

	i = 0;
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
