/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:47 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/06 11:59:37 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa (swap a): a stackinin en üstteki iki elemanını birbirileri ile yer değiştirin.
// Eğer yalnızca bir eleman var ise veya hiç eleman yoksa bir şey yapmayın.

// sb (swap b): b stackinin en üstteki iki elemanını birbirileri ile yer değiştirin.
// Eğer yalnızca bir eleman var ise veya hiç eleman yoksa bir şey yapmayın.

// ss : sa ve sb aksiyonlarının ikisini de çalıştır.

#include "../push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*head;
	t_list	*second;
	
	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	head = *a;
	second = head->next;
	head->next = second->next;
	second->next = head;
	(*a) = second;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **b)
{
	t_list	*head;
	t_list	*second;
	
	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	head = *b;
	second = head->next;
	head->next = second->next;
	second->next = head;
	(*b) = second;
	write(1, "sb\n", 3);
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
// 	t_list *a;
// 	t_list *b;

// 	a = NULL;
// 	b = NULL;
// 	add_new(&a, 3);
// 	add_new(&a, 2);
// 	add_new(&a, 1);
// 	add_new(&b, 4);
// 	add_new(&b, 5);

// 	print_stack(a);
// 	print_stack(b);

// 	swap_a(&a);
// 	swap_a(&b);

// 	print_stack(a);
// 	print_stack(b);
// 	return (0);
// }