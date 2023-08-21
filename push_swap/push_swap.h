/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:55 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/21 17:43:01 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "libft/includes/libft.h"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0m"
# define MAGENTA	"\e[0;35m"

typedef struct s_plist {
	int				data;
	int				pos;
	struct s_plist	*next;
}	t_plist;

// General functions
void	errors(void);
int		*handle_args(int counter, char **values, t_plist **start);

// Array Functions
void	bubble_sort(int *arr, int size);
void	print_array(int *arr, int size);
int		get_array_index(int *arr, int size, int nb);

// List Functions
void	add_list_end(t_plist **start, int num);
size_t	list_length(t_plist **start);
void	print_list(t_plist **start);
void	set_list_positions(t_plist **start, int *array, int array_size);
void	print_list_long(t_plist **start);




#endif 
