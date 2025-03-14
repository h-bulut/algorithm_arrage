/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:41 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 07:34:32 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse(t_list **stack)
{
	t_list *dup;
	t_list *last;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		return ;
	dup = *stack;
	last = NULL;
	
	while (dup->next != NULL)
	{
		last = dup;
		dup = dup->next;
	}
	last->next = NULL;
	dup->next = *stack;
	(*stack) = dup;
}

void reverse_rotate_a(t_list **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void reverse_rotate_b(t_list **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void reverse_rotate_ab(t_list **a, t_list **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}

