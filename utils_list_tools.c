/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:28:23 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 10:41:45 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
} 

void	ft_newback(t_list **stack, int i)
{
	t_list	*node;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = i;
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	node = ft_lstlast(*stack);
	node->next = new;
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	order_ok_increasing(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	order_ok_decreasing(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack && stack->next)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
