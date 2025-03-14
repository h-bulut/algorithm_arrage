/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:29:40 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 13:39:18 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int order(t_list **a, t_list **b)
{
	if(ft_lstsize((*a)) == 2 && !(*b))
	{
		swap_a((a));
		return (1);
	}
	else if (ft_lstsize((*a)) == 4)
	{
		push_b(a, b);
		return (2);
	}
	else if(ft_lstsize((*a)) > 4)
	{
		push_b(a,b);
		push_b(a,b);	
	}
	return(0);
}

int	main(int argc, char *argv[])
{
	t_list	**b;
	t_list	**a;

	b = malloc(sizeof(t_list *));
	if (!b)
		return (1);
	if (argc >= 2)
	{
		a = init_stack(argc, argv);
		if (!a)
			return (0);
		if (order_ok_increasing(*a) == 1)
			return (0);
		if (order(a, b) == 1)
			return (0);
		sent_b(a, b);
		order_b(b);
		order_for_tree(a);
		order_a(a);
		sent_a(a, b);
		print_stack((*a));
	}
	return (0);
}
