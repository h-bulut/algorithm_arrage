/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:08:47 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 03:20:15 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
