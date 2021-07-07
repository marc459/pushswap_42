/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:28:08 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/07 19:29:54 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*ft_iteratespaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (str + i);
}

int	ft_bidintlen(int *arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

int	*bidchartointarray(char **bid_char)
{
	int	i;
	int	*strnums;

	i = 0;
	strnums = malloc(sizeof(int) * ft_bidstrlen(bid_char));
	while (i < ft_bidstrlen(bid_char))
	{
		strnums[i] = ft_atoi(bid_char[i]);
		i++;
	}
	return (strnums);
}

int	*linkedlisttointarray(t_stack *lst)
{
	int	lstsize;
	int	*arrayint;
	int	i;

	i = 0;
	lstsize = ft_lstsize(lst);
	arrayint = malloc(sizeof(int) * lstsize);
	while (i < lstsize)
	{
		arrayint[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (arrayint);
}
