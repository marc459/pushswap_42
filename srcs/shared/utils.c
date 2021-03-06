/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:59:16 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/07 21:09:04 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_node(int content)
{
	char	*str;
	char	*cont;

	cont = ft_itoa(content);
	str = ft_strjoin(cont, " ");
	ft_putstr(str);
	free(str);
	free(cont);
}

int	str_error(char *s)
{
	int		i;

	i = 0;
	ft_putstr_fd(s, 2);
	exit (-1);
}

int	str_isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '-')
			return (0);
		else if (str[i] == '-' && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (0);
		else if (str[i] == '-' && (str[i - 1] >= '0' && str[i - 1] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack) != NULL)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		free(tmp);
	}
}

int	already_sort(t_stack *stack)
{
	int	tmp;

	tmp = stack->content;
	stack = stack->next;
	while (stack != NULL)
	{
		if (tmp > stack->content)
			return (0);
		tmp = stack->content;
		stack = stack->next;
	}
	return (1);
}
