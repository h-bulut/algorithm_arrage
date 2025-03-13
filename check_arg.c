/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasretdenizbulut <hasretdenizbulut@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:43:09 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/13 00:08:29 by hasretdeniz      ###   ########.fr       */
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
	// if (ft_strlen(arg) == 0)
	// 	return (0);
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
			if (!arg && !control_double_ptr(arg))
			{
				ft_putendl_fd("Error1", 2);
				free_trash(arg);
				exit(1);
			}
			free_trash(arg);
		}
		else
		{
			if (!control_ptr(argv[i]))
			{
				ft_putendl_fd("Error2", 2);
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
    long j = ft_atol(nbr);
    if (j < INT_MIN || j > INT_MAX)
    {
       ft_putendl_fd("Error", 2);
        exit (1);
    }
	ft_newback(stack, (int)j);	
}

void 	add_alot(t_list **stack, char *nbr)
{
	int i = 0;
    long j = 0;
	if (!nbr)
		return ;
	char **arg = ft_split(nbr, ' ');
	while (arg[i])
	{
        j = ft_atol(arg[i]);
        if (j < INT_MIN || j > INT_MAX)
        {
            ft_putendl_fd("Error", 2);
            exit (1);
        }
		ft_newback(stack, (int)j);
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
				ft_putendl_fd("Error3", 2);
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
    if (!stack)
        return;
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

int maximum(t_list *b)
{
    if (!b)
        exit(1);
    t_list *stack = b;
    int max = (stack)->value; 
    while (stack)
    {
        if (max < stack->value)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

int minimum(t_list *b)
{
    if (!b)
        exit(1);
    t_list *stack = b;
    int min = (stack)->value; 
    while (stack)
    {
        if (min > stack->value)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

int who_small(t_list *b, int i)
{
    t_list *stack = b;
    int small = INT_MIN;
    int max = 0;
    while (stack)
    {
        if (i > stack->value && (small == INT_MIN || stack->value > small))
        {
            small = stack->value;
            max = 1;
        }
        stack = stack->next;
    }
    if (max)
        return(small);
    return (maximum(b));
}

int calculator(int i, int j)
{
	if (j > 0 && i > 0)
	{
		if(j > i)
			return (j);
		return (i);
	}
	else if ((j < 0 && i > 0) || (j > 0 && i < 0))
	{
		if(j > i)
			return (j - i);
		return (i - j);
	}
	else if (j < 0 && i < 0)
	{
		if(j > i)
			return (i * (-1));
		return (j * (-1));
	}
    return (0);
}

int cost_b(t_list *a, t_list *b)
{
	if (!b)
		return (0);
	
    int i = 0;
	int j = ft_lstsize(b);
    
	int target = who_small(b, a->value);
	while (b && b->value != target)
	{
		i++;
		b = b->next;
	}
	if (j / 2 < i)
            i = i - j;
    return (i);
}

int arrange_stack(t_list *a, t_list *b)
{
	int node = 0;
	int i = INT_MAX;
	int j = 0;

	while(a)
	{
		int cost = calculator(cost_b(a, b), j);
		if( cost < i)
		{
			i = cost;
			node = a->value; 	
		}
		a = a->next;
	}
	return (node);
}

int steps_stack_a(t_list *a, t_list *b)
{
	int a_node = arrange_stack(a, b);
    int len_a = ft_lstsize(a);
	int i = 0;
	
	while (a_node != a->value)
		a = a->next;
	i = (len_a / 2) - ft_lstsize(a);
    return(i);
}
int steps_stack_b(t_list *a, t_list *b)
{
    int a_node = arrange_stack(a, b);
	int b_node = who_small(b, a_node);
    int len_b = ft_lstsize(b);
	int j = 0;
	
	while (b_node != b->value)
		b = b->next;
	j = (len_b / 2) - ft_lstsize(b);
    return (j);
}

int main(int argc, char *argv[])
{
    t_list *b = NULL;
	if (argc >= 2)
	{
		t_list *a = init_stack(argc, argv);
        if (!a)
            exit (1);
        if (ft_lstsize(a) > 3)
        {
            push_b(&a, &b);
            push_b(&a, &b);
        } 
        printf("stack_a hamle sayısı : %d\n", steps_stack_a(a, b));
        printf("stack_b hamle sayısı : %d\n", steps_stack_b(a, b));
        // steps_stack_a(a, b);
        // print_stack(a);
        // printf("*\n");
        // print_stack(b); //neden buradan gönderdiğim stack başka bir fonksiyonu steps yaptığımda görüntü alamıyorum   
	}
	return (0);
}

// printf("stack_a\n");
// print_stack(a);
// printf("stack_b\n");
// print_stack(b);