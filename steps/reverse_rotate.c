/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:41 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/06 12:00:20 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rra (reverse rotate a): a stackinin bütün elemanlarını bir aşağı kaydırın.
// Son eleman artık ilk eleman olacaktır.

// rrb (reverse rotate b): b stackinin bütün elemanlarını bir aşağı kaydırın.
// Son eleman artık ilk eleman olacaktır.

// rrr : rra ve rrb aksiyonlarının ikisini de çalıştırır

#include "../push_swap.h"

void	reverse_rotate_a(t_list **a)
{
	t_list *dup;
	t_list *last;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	dup = *a;
	last = NULL;
	
	while (dup->next != NULL)
	{
		last = dup;
		dup = dup->next;
	}
	last->next = NULL;
	dup->next = *a;
	(*a) = dup;
	write(1, "rra\n", 4);
	
}
void	reverse_rotate_b(t_list **b)
{
	t_list *dup;
	t_list *last;

	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	dup = *b;
	last = NULL;
	while (dup->next != NULL)
	{
		last = dup;
		dup = dup->next;
	}
	last->next = NULL;
	dup->next = *b;
	(*b) = dup;
	write(1, "rrb\n", 4);
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

// 	reverse_rotate_a(&a);

// 	print_stack(a);
// 	print_stack(b);
// 	return (0);
// }

