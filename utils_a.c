/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:27:29 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 13:44:26 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	who_small(t_list *b, int i)
{
	t_list	*stack;
	int		small;
	int		max;

	stack = b;
	small = INT_MIN;
	max = 0;
	while (stack)
	{
		if (i > stack->value && (small == INT_MIN || stack->value > small))
		{
			small = stack->value;
			max = 1;
		}
		stack = stack->next;
	}
	if (max)
		return (small);
	return (maximum(b));
}

int	cost_b(t_list *a, t_list *b)
{
	int	i;
	int	len;
	int	target;

	if (!b)
		return (0);
	i = 0;
	len = ft_lstsize(b);
	target = who_small(b, a->value);
	while (b && b->value != target)
	{
		i++;
		b = b->next;
	}
	if (len / 2 < i)
		i = i - len;
	return (i);
}

int	arrange_stack_a(t_list *a, t_list *b)
{
	int	node;
	int	i;
	int	j;
	int	cost;

	node = 0;
	i = INT_MAX;
	j = 0;
	while (a)
	{
		cost = calculator(cost_b(a, b), j);
		if (cost < i)
		{
			i = cost;
			node = a->value;
		}
		a = a->next;
	}
	return (node);
}

int	steps_stack_a(t_list *a, t_list *b)
{
	int	a_node;
	int	j;
	int	len;

	a_node = arrange_stack_a(a, b);
	j = 0;
	len = ft_lstsize(a);
	while (a_node != a->value)
	{
		j++;
		a = a->next;
	}
	if (j > len / 2)
		j = j - len;
	return (j);
}

int	steps_stack_b(t_list *a, t_list *b)
{
	int a_node = arrange_stack_a(a, b);
	int b_node = who_small(b, a_node);
	int i = 0;

	int len = ft_lstsize(b);
	while (b_node != b->value)
	{
		i++;
		b = b->next;
	}
	if (i > len / 2)
		i = i - len;
	return (i);
}