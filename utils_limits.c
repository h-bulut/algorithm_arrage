/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:27:51 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 13:49:05 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int maximum(t_list *b)
{
    if (!b)
        exit(1);
    t_list *stack = b;
    int max = (stack)->value; 
    while (stack)
    {
        if (max < stack->value)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

int minimum(t_list *b)
{
    if (!b)
        exit(1);
    t_list *stack = b;
    int min = (stack)->value; 
    while (stack)
    {
        if (min > stack->value)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

void move(t_list **a, t_list **b, int i, int j)
{
	if (i > 0 && j > 0)
	{
		while (i-- > 0 && j-- > 0)
			rotate_ab(a, b);
		while (i-- > 0)
			rotate_a(a);
		while (j-- > 0)
			rotate_b(b);
	}
	else if (i > 0 && j < 0)
	{
		while(i-- > 0)
			rotate_a(a);
		while(j++ < 0)
			reverse_rotate_b(b);	
	}
	else if (i < 0 && j > 0)
	{
		while(i++ < 0)
			rotate_a(a);
		while(j-- < 0)
			reverse_rotate_b(b);	
	}
	else if(i < 0 && j < 0)
	{
		while (i++ < 0 && j++ < 0)
			reverse_rotate_ab(a,b);
		while(i++ < 0)
			reverse_rotate_a(a);
		while (j++ < 0)
			reverse_rotate_b(b);
	}
}
