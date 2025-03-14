/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:09:39 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 12:34:54 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_list	t_list;

typedef struct s_list
{
	int					value;
	t_list				*next;

}						t_list;

void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	reverse_rotate_ab(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_list **a, t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **b);

//check_arg.c 
int	control_ptr(char *arg);
int	control_double_ptr(char **arg);
int	check_args(int argc, char **argv);
void	check_dup(t_list *stack_a);
t_list	**init_stack(int argc, char **argv);

//main.c
void	print_stack(t_list *stack);
int order_small(t_list **a, t_list **b);

//utils_a.c
int who_small(t_list *b, int i);
int cost_b(t_list *a, t_list *b);
int arrange_stack_a(t_list *a, t_list *b);
int steps_stack_a(t_list *a, t_list *b);
int steps_stack_b(t_list *a, t_list *b);

//utils_b.c
int who_big(t_list *a, int i);
int cost_a(t_list *a, t_list *b);
int arrange_stack_b(t_list *a, t_list *b);
int steps_stack_bb(t_list *a, t_list *b);
int steps_stack_aa(t_list *a, t_list *b);

//utils_limits.c
int maximum(t_list *b);
int minimum(t_list *b);
void move(t_list **a, t_list **b, int i, int j);

//utils_list_tools.c
t_list	*ft_lstlast(t_list *lst);
void	ft_newback(t_list **stack, int i);
int	ft_lstsize(t_list *stack);
int	order_ok_increasing(t_list *stack);
int	order_ok_decreasing(t_list *stack);

//utils_order.c
void	order_for_tree(t_list **stack);
void	sent_b(t_list **a, t_list **b);
void	sent_a(t_list **a, t_list **b);
void	order_b(t_list **b);
void	order_a(t_list **a);

//utils_tools.c
void	free_trash(char **str);
long	ft_atol(const char *str);
void	add_alot(t_list **stack, char *nbr);
void	add_one(t_list **stack, char *nbr);
int	calculator(int i, int j);

#endif
