/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:09:39 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/06 17:03:45 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list	t_list;

typedef struct s_list
{
	int					value;
	t_list				*next;

}						t_list;

void	free_trash(char **str);
int		check_args(int argc, char **argv);
int		control_ptr(char *arg);
int		control_double_ptr(char **arg);



void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **b);


long	ft_atol(const char *str);
void	ft_newback(t_list **stack, int i);
void	add_one(t_list **stack, char *nbr);
void 	add_alot(t_list **stack, char *nbr);
t_list *init_stack(int argc, char **argv);
void	print_stack(t_list *stack);
t_list	*ft_lstlast(t_list *lst);
void  check_dup(t_list *stack_a);

#endif
