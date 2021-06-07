/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:58:45 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/07 16:25:56 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*concatenate_args(char **args, int size)
{
	char	*tmp;
	char	*args_str;
	int		i;

	args_str = ft_strjoin(args[0], " ");
	i = 0;
	while (++i < size)
	{
		tmp = ft_strjoin(args[i], " ");
		args_str = ft_strjoin(args_str, tmp);
		free(tmp);
	}
	return (args_str);
}

void	arg_save(t_stack **stack_a, char *str_args)
{
	int		i;
	long	num;
	char	**splited_args;
	t_stack	*aux;
	t_stack	*newnode;

	newnode = NULL;
	i = 0;
	splited_args = ft_split(str_args, ' ');
	while (i < ft_bidstrlen(splited_args))
	{
		num = ft_atol(splited_args[i]);
		if (num > 2147483647 || num < -2147483648)
			str_error("Error\n");
		aux = newnode;
		newnode = ft_lstnew(num);
		newnode->prev = aux;
		ft_lstadd_back(stack_a, newnode);
		i++;
	}
	free_double_ptr(splited_args);
}

int	arg_checker(char **splited_args)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_bidstrlen(splited_args))
	{
		if (!str_isnumber(splited_args[i]))
			return (0);
		while (j < ft_bidstrlen(splited_args))
		{
			if (ft_strcmp(splited_args[i], splited_args[j]) && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	free_double_ptr(splited_args);
	return (1);
}

void	free_double_ptr(char **s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		free(s[i]);
		i++;
	}
	free(s);
}
