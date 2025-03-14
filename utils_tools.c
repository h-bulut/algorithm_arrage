/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:29:19 by hbulut            #+#    #+#             */
/*   Updated: 2025/03/14 13:14:52 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void	free_trash(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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

void	add_alot(t_list **stack, char *nbr)
{
	int		i;
	long	j;
	char	**arg;

	i = 0;
	j = 0;
	if (!nbr)
		return ;
	arg = ft_split(nbr, ' ');
	while (arg[i])
	{
		j = ft_atol(arg[i]);
		if (j < INT_MIN || j > INT_MAX)
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		ft_newback(stack, (int)j);
		i++;
	}
	free_trash(arg);
}

void	add_one(t_list **stack, char *nbr)
{
	long	j;

	if (!nbr)
		return ;
	j = ft_atol(nbr);
	if (j < INT_MIN || j > INT_MAX)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	ft_newback(stack, (int)j);
}

int	calculator(int i, int j)
{
	if (j > 0 && i > 0)
	{
		if (j > i)
			return (j);
		return (i);
	}
	else if ((j < 0 && i > 0) || (j > 0 && i < 0))
	{
		if (j > i)
			return (j - i);
		return (i - j);
	}
	else if (j < 0 && i < 0)
	{
		if (j > i)
			return (i * (-1));
		return (j * (-1));
	}
	return (0);
}