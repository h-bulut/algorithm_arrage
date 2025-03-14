/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:44 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 07:34:16 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void rotate(t_list **a)
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
}

void rotate_a(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void rotate_b(t_list **b)
{
	rotate(b);
	write(1,"rb\n", 3);
}

void rotate_ab(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
