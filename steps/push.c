/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:39 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 03:19:41 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
