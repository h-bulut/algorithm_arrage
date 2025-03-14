/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:27:43 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 13:45:58 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	who_big(t_list *a, int i)
{
	t_list	*stack;
	int		big;
	int		min;

	stack = a;
	big = INT_MAX;
	min = 0;
	while (stack)
	{
		if (i < stack->value && (big == INT_MAX || stack->value < big))
		{
			big = stack->value;
			min = 1;
		}
		stack = stack->next;
	}
	if (min)
		return (big);
	return (minimum(a));
}

int	cost_a(t_list *a, t_list *b)
{
	int	i;
	int	len;
	int	target;

	if (!a)
		return (0);
	i = 0;
	len = ft_lstsize(a);
	target = who_big(a, b->value);
	while (a->value != target)
	{
		i++;
		a = a->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}

int	arrange_stack_b(t_list *a, t_list *b)
{
	int	node;
	int	i;
	int	j;
	int	cost;

	node = 0;
	i = INT_MAX;
	j = 0;
	while (b)
	{
		cost = calculator(cost_a(a, b), j);
		if (cost < i)
		{
			i = cost;
			node = b->value;
		}
		b = b->next;
	}
	return (node);
}

int	steps_stack_aa(t_list *a, t_list *b)
{
	int	b_node;
	int	a_node;
	int	i;
	int	len;

	b_node = arrange_stack_b(a, b);
	a_node = who_big(a, b_node);
	i = 0;
	len = ft_lstsize(a);
	while (a_node != a->value)
	{
		i++;
		a = a->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}

int	steps_stack_bb(t_list *a, t_list *b)
{
	int	b_node;
	int	j;
	int	len;

	b_node = arrange_stack_b(a, b);
	j = 0;
	len = ft_lstsize(b);
	while (b_node != b->value)
	{
		j++;
		b = b->next;
	}
	if (j > len / 2)
		j = j - len;
	return (j);
}
