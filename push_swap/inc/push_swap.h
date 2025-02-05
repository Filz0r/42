/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:55 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/17 14:39:14 by fparreir         ###   ########.fr       */
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
	t_plist		*parent;
	int			stack_size;
	int			total_size;
	int			smallest_in_stack;
	int			biggest_in_stack;
	char		stack;
}	t_info;

// General functions
void	errors(t_plist **start);
void	handle_args(int counter, char **values, t_plist **start);
void	info_init(t_plist **start);
void	update_info(t_plist **start, char stack);
void	sort_three(t_plist **stack);
void	sort_five(t_plist **root_a, t_plist **root_b);
void	sort_big(t_plist **a, t_plist **b);
void	push_swap(t_plist **a, t_plist **b);
int		check_number(long nb);
int		has_digits(const char *str);
void	free_list(t_plist **start);
void	free_words(char **arr);
char	**fuck_norm(const char *str, int *i);
void	fuck_norm2(char **values, int counter, t_plist **start);

// List Functions
void	add_list_end(t_plist **start, int num);
int		is_num_in_stack(t_plist **start, int nb);
int		is_sorted(t_plist **start);
void	set_smallest_and_biggest(t_plist **start);
int		list_size(t_plist **start);

//Print functions
void	print_list_long(t_plist **start);
void	print_list(t_plist **start);

//Math Functions
int		get_mean_number(t_plist **stack);
int		get_lowest_cost(t_plist **a, t_plist **b);
int		get_bf(t_plist **a, int bf_val);
int		get_cost(t_plist **a, t_plist **b, int bf, int current);
int		count_moves(t_plist **start, int length, int value);
void	put_b_on_top(t_plist **stack, int length, int bf_val);
void	put_a_on_top(t_plist **stack, int length, int bf);

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
void	pa(t_plist **stack_a, t_plist **stack_b, int trigger);
void	pb(t_plist **stack_a, t_plist **stack_b, int trigger);

#endif 
