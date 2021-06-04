/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 21:57:12 by msantos-          #+#    #+#             */
/*   Updated: 2021/05/30 17:11:36 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*position_node(t_stack *head, int position)
{
	t_stack	*tmp;
	int			count;

	tmp = head;
	count = 1;
	while (count < position && tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack	*greater(t_stack *head)
{
	t_stack		*tmp;

	tmp = head;
	while (tmp->next != NULL)
	{
		if (head->content < tmp->next->content)
			head = tmp->next;

		tmp = tmp->next;
	}
	return (head);
}

t_stack	*smaller(t_stack *head)
{
	t_stack		*tmp;

	tmp = head;
	while (tmp->next != NULL)
	{
		if (head->content > tmp->next->content)
			head = tmp->next;

		tmp = tmp->next;
	}
	return (head);
}