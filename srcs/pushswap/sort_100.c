/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:45:11 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/11 12:19:39 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	onehundred_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk)
{
	int		*sorted_stack_a;
	int		i;
	int		x;

	i = 0;
	x = 0;
	sorted_stack_a = ft_bubble_sort(linkedlisttointarray(*stack_a),
			chunk->n_args);
	while (x < chunk->n_chunks)
	{
		chunk->minnum_chunk = sorted_stack_a[chunk->n_perchunk * x];
		chunk->maxnum_chunk = sorted_stack_a[chunk->n_perchunk * x + chunk->n_perchunk - 1];
		while (i < chunk->n_perchunk)
		{
			find_closestn_chunk(stack_a, 'a', chunk->minnum_chunk,
				chunk->maxnum_chunk);
			pa_pb(stack_b, stack_a);
			ft_putstr("pb\n");
			i++;
		}
		i = 0;
		x++;
	}
	
	chunk->minnum_chunk = chunk->maxnum_chunk + 1;
	while (ft_lstsize(stack_a[0]))
	{
		find_closestn_chunk(stack_a, 'a', chunk->minnum_chunk,
			sorted_stack_a[chunk->n_args - 1]);
		pa_pb(stack_b, stack_a);
		ft_putstr("pb\n");
	}
	i = 1;
	while (ft_lstsize(stack_b[0]))
	{
		find_closestn_chunk(stack_b, 'b', sorted_stack_a[chunk->n_args - i],
			sorted_stack_a[chunk->n_args - i]);
		pa_pb(stack_a, stack_b);
		ft_putstr("pa\n");
		i++;
	}
	free(sorted_stack_a);
}
