/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasretdenizbulut <hasretdenizbulut@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:43:09 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/09 22:36:47 by hasretdeniz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_trash(char **str)
{
	int	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	control_ptr(char *arg)
{
	int	i = 0;
	if (ft_strlen(arg) == 0)
		return (0);
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
	int	i = 0;
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
	int		i = 0;
	char	**arg;
	
	while (++i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			arg = ft_split(argv[i], ' ');
			if (!arg || !control_double_ptr(arg))
			{
				ft_putendl_fd("Error", 2);
				free_trash(arg);
				exit(1);
			}
			free_trash(arg);
		}
		else
		{
			if (!control_ptr(argv[i]))
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
		}
	}
	return (1);
}

long	ft_atol(const char *str)
{
	size_t	i;
	int		k;
	long	s;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	k = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			k = -1;
		i++;
	}
	s = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		s = s * 10 + (str[i] - '0');
		i++;
	}
	return (s * k);
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void 	ft_newback(t_list **stack, int i)
{
	t_list *node;
	t_list *new = malloc(sizeof(t_list));
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

void	add_one(t_list **stack, char *nbr)
{
	if (!nbr)
		return ;
	ft_newback(stack, ft_atol(nbr));		
}

void 	add_alot(t_list **stack, char *nbr)
{
	int i = 0;
	if (!nbr)
		return ;
	char **arg = ft_split(nbr, ' ');
	while (arg[i])
	{
		ft_newback(stack, ft_atol(arg[i]));
		i++;
	}
	free_trash(arg);
}

void  check_dup(t_list *stack_a)
{
	t_list *head = NULL;
	t_list *iter;

	head = stack_a;
	while (head)
	{
		iter = head->next;
		while (iter)
		{
			if (iter->value == head->value)
			{
				ft_putendl_fd("Error", 2);
				exit(1);
			}
			iter = iter->next;
		}
		head = head->next;
	}
}
t_list *init_stack(int argc, char **argv)
{
	int i = 1;
	t_list *stack_a = NULL;

	if (check_args(argc, argv))
	{
		while( i < argc)
		{
			if (ft_strchr(argv[i], ' '))
				add_alot(&stack_a, argv[i]);
			else 
				add_one(&stack_a, argv[i]);
			i++;
		}
		check_dup(stack_a);
	}
	return (stack_a);
}

void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int ft_lstsize(t_list *stack)
{
    int i = 0;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}



// void cost_calculator(t_list *stack)
// {
//     int begin;
//     while(stack)
//     {
//         begin = stack;   
//     }
// }





int main(int argc, char *argv[])
{
    t_list *b = NULL;
	if (argc > 2)
	{
		t_list *a = init_stack(argc, argv);
        if (ft_lstsize(a) > 3)
        {
            push_b(&a, &b);
            push_b(&a, &b);
        }
        print_stack(a);
        printf("*\n");
        print_stack(b); 
	}

    
	return (0);
}

