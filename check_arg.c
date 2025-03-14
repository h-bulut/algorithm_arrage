 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:43:09 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 11:33:16 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	control_ptr(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	control_double_ptr(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!control_ptr(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int		i;
	char	**arg;
	
	i = 0;
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			arg = ft_split(argv[i], ' ');
			if (!arg && !control_double_ptr(arg))
			{
				ft_putendl_fd("Error1", 2);
				free_trash(arg);
				exit(1);
			}
			free_trash(arg);
		}
		else if (!control_ptr(argv[i]))
		{
			ft_putendl_fd("Error2", 2);
			exit(1);
		}
	}
	return (1);
}

void	check_dup(t_list *stack_a)
{
	t_list	*head;
	t_list	*iter;

	head = NULL;
	head = stack_a;
	while (head)
	{
		iter = head->next;
		while (iter)
		{
			if (iter->value == head->value)
			{
				ft_putendl_fd("Error3", 2);
				exit(1);
			}
			iter = iter->next;
		}
		head = head->next;
	}
}

t_list	**init_stack(int argc, char **argv)
{
	int		i;
	t_list	**stack_a;

	i = 1;
	stack_a = malloc(sizeof(t_list *));
	if (!stack_a)
		return (NULL);
	(*stack_a) = NULL;
	if (check_args(argc, argv))
	{
		while (i < argc)
		{
			if (ft_strchr(argv[i], ' '))
				add_alot(stack_a, argv[i]);
			else
				add_one(stack_a, argv[i]);
			i++;
		}
		check_dup((*stack_a));
	}
	return (stack_a);
}
