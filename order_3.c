/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:39:33 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/06 21:43:51 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*stack)->content;
	num2 = (*stack)->next->content;
	num3 = (*stack)->next->next->content;
	if (num1 > num2 && num3 > num2 && num1 < num3)
	{
		sa_sb(stack);
		ft_putstr("sa\n");
	}
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa_sb(stack);
		ft_putstr("sa\n");
		rra_rrb(stack);
		ft_putstr("rra\n");
	}
	else if (num1 > num2 && num2 < num3 && num1 > num3)
	{
		ra_rb(stack);
		ft_putstr("ra\n");
	}
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa_sb(stack);
		ft_putstr("sa\n");
		ra_rb(stack);
		ft_putstr("ra\n");
	}
	else if (num1 < num2 && num2 > num3 && num1 > num3)
	{
		rra_rrb(stack);
		ft_putstr("rra\n");
	}
}
