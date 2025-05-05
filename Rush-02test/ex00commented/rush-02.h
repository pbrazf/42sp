#ifndef FT_H
# define FT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define DICT_SIZE 100

typedef struct s_list
{
	char *nbr;
	char *number_name;
}	t_list;

int is_numeric_string(char *str);
int	dict_supports_input(char *nbr_str, t_list *list);
t_list	*create_list(char *file);
char	*ft_strdup(char *src);
void	ft_print_big(char *nbr_str, t_list *list, int *first);
int	ft_strlen(char *str);
void	ft_putstr(char *str);
void	print_hundred_block(char *block, t_list *list, int *first);
void	print_tens_block(char *block, t_list *list, int *first);
void	extract_block(char *nbr_str, char *block, int block_index, int len);
int	is_zero_block(char *block);
void	print_number_block(char *block, t_list *list, int *first);
char	*find_in_dict(char *key, t_list *list);
void	free_list(t_list *list);

#endif