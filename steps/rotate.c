/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasretdenizbulut <hasretdenizbulut@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:44 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/12 22:42:22 by hasretdeniz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ra (rotate a): a stackinin bütün elemanlarını bir yukarı kaydırın.
// İlk eleman artık son eleman olacaktır.

// rb (rotate b): b stackinin bütün elemanlarını bir yukarı kaydırın.
// İlk eleman artık son eleman olacaktır.

// rr : ra ve rb aksiyonlarının ikisini de çalıştır.

#include "../push_swap.h"

void rotate_a(t_list **a)
{
	t_list *dup;
	t_list *last;

	if (a == NULL || (*a) == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	dup = *a;
	while (dup->next != NULL)
		dup = dup->next;
	dup->next = last;
	*a = last->next;
	last->next = NULL;
	write(1, "ra\n", 3);
}

void rotate_b(t_list **b)
{
	t_list *dup;
	t_list *last;

	if (b == NULL || (*b) == NULL || (*b)->next == NULL)
		return ;
	last = *b;
	dup = *b;
	while (dup->next != NULL)
		dup = dup->next;
	dup->next = last;
	*b = last->next;
	last->next = NULL;
	write(1, "rb\n", 3);
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

// 	rotate_a(&a);
// 	rotate_b(&b);

// 	print_stack(a);
// 	print_stack(b);
// 	return (0);
// }
