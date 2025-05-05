/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrferr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:47:54 by pedrferr          #+#    #+#             */
/*   Updated: 2025/05/04 20:48:43 by pedrferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define DICT_SIZE 100

typedef struct s_list
{
	char	*nbr;
	char	*number_name;
}	t_list;

typedef struct s_context
{
	t_list	*list;
	int		first;
}	t_context;

int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);

t_list	*create_list(char *file);
void	free_list(t_list *list);
int		dict_supports_input(char *nbr_str, t_list *list);

int		is_numeric_string(char *str);

void	ft_print_big(char *nbr_str, t_context *ctx);
int		is_zero_block(char *block);
void	handle_block(char *block, int i, int total, t_context *ctx);

void	print_block(char *block, t_context *ctx);
void	print_number_block(char *block, t_context *ctx);
void	print_tens_block(char *block, t_context *ctx);
void	print_hundred_block(char *block, t_context *ctx);
void	print_split_tens(char *block, t_context *ctx);

void	extract_block(char *nbr_str, char *block, int block_index, int len);
char	*find_in_dict(char *key, t_list *list);
int		compare_nbr_str(char *a, char *b);

#endif
