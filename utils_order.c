/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:28:51 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 13:41:20 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_for_tree(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(stack);
	else if (first > second && second > third)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (first > second && second < third && first > third)
		rotate_a(stack);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack);
}

void	sent_b(t_list **a, t_list **b)
{
	int	i;
	int	j;

	while (ft_lstsize((*a)) > 3)
	{
		i = steps_stack_a((*a), (*b));
		j = steps_stack_b((*a), (*b));
		move(a, b, i, j);
		push_b(a, b); 
	}
}

void	order_b(t_list **b)
{
	int		c;
	t_list	*b_stack;
	int		len;

	len = ft_lstsize((*b));
	c = 0;
	b_stack = (*b);
	while (b_stack->value != maximum((*b)))
	{
		c++;
		b_stack = b_stack->next;
	}
	if (c > len / 2)
		c = c - len;
	if (c > 0)
	{
		while (c--)
			rotate_b(b);
	}
	else if (c < 0)
	{
		while (c++)
			reverse_rotate_b(b);
	}
}

void	sent_a(t_list **a, t_list **b)
{
	int	i;
	int	j;

	while (ft_lstsize((*b)))
	{
		i = steps_stack_aa((*a), (*b));
		j = steps_stack_bb((*a), (*b));
		move(a, b, i ,j);
		push_a(a, b);
	}
}

void	order_a(t_list **a)
{
	int		d;
	t_list	*a_stack;
	int len = ft_lstsize((*a));

	d = 0;
	a_stack = (*a);
	while (a_stack->value != minimum((*a)))
	{
		d++;
		a_stack = a_stack->next;
	}
	if (d > (len / 2))
		d = d - len;
	if (d > 0)
	{
		while (d--)
			rotate_a(a);
	}
	else if (d < 0)
	{
		while (d++)
			reverse_rotate_a(a);
	}
}
