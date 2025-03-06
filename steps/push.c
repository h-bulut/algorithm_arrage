/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:39 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/06 11:59:15 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pa (push a): b stackinin en üstündeki elemanı a stackinin en üstüne koyun.
// Eğer b stacki boş ise bir şey yapmayın.

// pb (push b): a stackinin en üstündeki elemanı b stackinin en üstüne koyun.
// Eğer a stacki boş ise bir şey yapmayın.

#include "../push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (b == NULL || (*b) == NULL || a == NULL)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (b == NULL || a == NULL || (*a) == NULL)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

// void	add_new(t_list **stack, int value)
// {
// 	t_list	*new_node;

// 	new_node = malloc(sizeof(t_list));
// 	if (!new_node)
// 		return ;
// 	new_node->value = value;
// 	new_node->next = *stack;
// 	*stack = new_node;
// }

// void	print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d\n", stack->value);
// 		stack = stack->next;
// 	}
// 	printf("NULL*\n");
// }

// int	main(int argc, char **argv)
// {
// 	t_list	*a;
// 	t_list	*b;

// 	a = NULL;
// 	b = NULL;
// 	add_new(&a, 3);
// 	add_new(&a, 2);
// 	add_new(&a, 1);
// 	add_new(&b, 4);
// 	add_new(&b, 5);

// 	print_stack(a);
// 	print_stack(b);

// 	push_a(&a, &b);

// 	print_stack(a);
// 	print_stack(b);
// 	return (0);
// }
