/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:58:45 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/07 21:11:02 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*concatenate_args(char **args, int size)
{
	char	*tmp;
	char	*tmp2;
	char	*args_str;
	int		i;

	args_str = ft_strjoin(args[0], " ");
	i = 1;
	while (i < size)
	{
		tmp = ft_strjoin(args[i], " ");
		tmp2 = ft_strdup(args_str);
		free(args_str);
		args_str = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		i++;
	}
	return (args_str);
}

void	arg_save(t_stack **stack_a, char **splited_args)
{
	int		i;
	long	num;
	t_stack	*aux;
	t_stack	*newnode;

	newnode = NULL;
	i = 0;
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
}

int	arg_checker(char **splited_args)
{
	int		i;
	int		j;
	int		*args;

	i = 0;
	j = 0;
	args = bidchartointarray(splited_args);
	while (i < ft_bidstrlen(splited_args))
	{
		if (!str_isnumber(splited_args[i]))
			return (ft_free_return(args, 0));
		while (j < ft_bidstrlen(splited_args))
		{
			if ((ft_strcmp(splited_args[i], splited_args[j])
					|| args[i] == args[j]) && i != j)
				return (ft_free_return(args, 0));
			j++;
		}
		j = 0;
		i++;
	}
	return (ft_free_return(args, 1));
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
