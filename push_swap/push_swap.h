/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:45:55 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/30 15:00:03 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include "libft/includes/libft.h"

typedef struct ps_list
{
	int				*a_stack;
	int				*b_stack;
	int				length; 
}	t_ps_list;

void		errors(int err_type);
t_ps_list	handle_args(int counter, char **values);
void		sort_small(int counter, t_ps_list stack);
void		sort_big(int counter, t_ps_list stack);
t_ps_list	swap(t_ps_list stack, char current);
void		rotate(int *stack);
void		push(int *stack);
void		reverse_rotate(int *stack);
void		change_both(int *a_stack, int *b_stack, char *operation);
int			is_sorted(t_ps_list stack); 

#endif 
