/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:55 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 10:34:34 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "../libft/includes/libft.h"

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
	struct s_info	*info;
	struct s_plist	*next;
}	t_plist;

typedef struct s_info {
	struct s_plist	*parent;
	int				curr_pos;
	int				final_pos;
	char			stack;
	int				stack_size;
	int				sa;
	int				sb;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}	t_info;

// General functions
void	errors(void);
int		*handle_args(int counter, char **values, t_plist **start);
void	info_init(t_plist **start, int *arr, int size);
void	initialize_move_counters(t_plist **start);
void	sort_three(t_plist **stack_a, t_plist **stack_b);

// Array Functions
void	bubble_sort(int *arr, int size);
int		get_array_index(int *arr, int size, int nb);

// List Functions
void	add_list_end(t_plist **start, int num);
size_t	list_length(t_plist **start);
int		is_num_in_stack(t_plist **start, int nb);

//Print functions
void	print_moves(t_plist **start);
void	print_list_long(t_plist **start);
void	print_list(t_plist **start);
void	print_array(int *arr, int size);

//Move Functions
void	sa(t_plist **stack_a, int trigger);
void	sb(t_plist **stack_b, int trigger);
void	ss(t_plist **stack_a, t_plist **stack_b);
void	ra(t_plist **stack_a, int trigger);
void	rb(t_plist **stack_b, int trigger);
void	rr(t_plist **stack_a, t_plist **stack_b);
void	rra(t_plist **stack_a, int trigger);
void	rrb(t_plist **stack_b, int trigger);
void	rrr(t_plist **stack_a, t_plist **stack_b);
void	pa(t_plist **stack_a, int trigger);
void	pb(t_plist **stack_b, int trigger);

#endif 
