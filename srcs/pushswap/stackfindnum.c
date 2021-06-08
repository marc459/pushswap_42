/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfindnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:45:06 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/08 19:46:49 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_holdfirst(t_stack **stack_a, int minnum_chunk, int maxnum_chunk)
{
	int		i;
	int		hold_first;
	t_stack	*tmp;

	tmp = *stack_a;
	i = 0;
	hold_first = 0;
	while (tmp != NULL && hold_first == 0)
	{
		if (tmp->content >= minnum_chunk && tmp->content <= maxnum_chunk)
			hold_first = i;
		tmp = tmp->next;
		i++;
	}
	return (hold_first);
}

int	find_holdlast(t_stack **stack_a, int minnum_chunk, int maxnum_chunk)
{
	int		i;
	int		hold_last;
	int		*stack;
	t_stack	*tmp;

	stack = linkedlisttointarray(*stack_a);
	tmp = *stack_a;
	i = ft_lstsize(tmp) - 1;
	hold_last = 0;
	while (i >= 0)
	{
		hold_last++;
		if (stack[i] >= minnum_chunk && stack[i] <= maxnum_chunk)
			break ;
		i--;
	}
	free(stack);
	return (hold_last);
}

void	find_closestn_chunk(t_stack **stack, char selected_stack, int minnum_chunk, int maxnum_chunk)
{
	int	hold_first;
	int	hold_last;
	int	i;

	i = 0;
	hold_first = find_holdfirst(stack, minnum_chunk, maxnum_chunk);
	hold_last = find_holdlast(stack, minnum_chunk, maxnum_chunk);
	if (hold_last < hold_first)
	{
		while (i < hold_last)
		{
			rra_rrb(stack);
			if (selected_stack == 'a')
				ft_putstr("rra\n");
			else
				ft_putstr("rrb\n");
			i++;
		}
	}
	else
	{
		while (i < hold_first)
		{
			ra_rb(stack);
			if (selected_stack == 'a')
				ft_putstr("ra\n");
			else
				ft_putstr("rb\n");
			i++;
		}
	}
}
