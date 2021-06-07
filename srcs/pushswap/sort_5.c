/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 13:53:48 by marcos            #+#    #+#             */
/*   Updated: 2021/06/07 16:25:51 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	*sorted_stack_a;

	i = 0;
	sorted_stack_a = ft_bubble_sort(linkedlisttointarray(*stack_a),
			ft_lstsize(*stack_a));
	while (ft_lstsize(*stack_a) != 3)
	{
		find_closestn_chunk(stack_a, 'a', sorted_stack_a[i], sorted_stack_a[i]);
		pa_pb(stack_b, stack_a);
		ft_putstr("pb\n");
		i++;
	}
	three_sort(stack_a);
	i = 1;
	while (ft_lstsize(*stack_b))
	{
		find_closestn_chunk(stack_b, 'b', sorted_stack_a[i], sorted_stack_a[i]);
		pa_pb(stack_a, stack_b);
		ft_putstr("pa\n");
		i--;
	}
}
