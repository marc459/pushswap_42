/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 13:25:46 by msantos-          #+#    #+#             */
/*   Updated: 2021/05/31 21:08:28 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **stack)
{
	t_stack *tmp;

	if (!(ft_lstsize(*stack) < 2))
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	pa_pb(t_stack **stack1,t_stack **stack2)
{
	if (ft_lstsize(*stack2) > 0)
	{
		t_stack *tmp;
		tmp = *stack2;

		*stack2 = (*stack2)->next;
		ft_lstadd_front(stack1,tmp);	
	}
}

void	ra_rb(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!(ft_lstsize(*stack) < 2))
	{
		tmp = *stack;
		tmp2 = tmp->next;
		while (ft_lstsize(*stack) > 1)
			*stack = (*stack)->next;

		(*stack)->next = tmp;
		tmp->next = NULL;
		*stack = tmp2;
	}
}

void	rra_rrb(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (!(ft_lstsize(*stack) < 2))
	{
		
		tmp2 = (*stack);
		while (ft_lstsize(*stack) > 2)
			*stack = (*stack)->next;
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		(*stack)->next = tmp2;
	}
}