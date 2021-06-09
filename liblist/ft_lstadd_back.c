/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:30:21 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/09 16:48:13 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastnode;

	if (new)
	{
		lastnode = ft_lstlast(lst[0]);
		if (*lst == NULL)
		{
			*lst = new;
			new->next = NULL;
		}
		else
		{
			lastnode->next = new;
			new->next = NULL;
		}
	}
}
