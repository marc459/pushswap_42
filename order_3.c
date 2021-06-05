/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:39:33 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/05 22:41:15 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stack **stack)
{
	int num1;
	int num2;
	int num3;

	num1 = (*stack)->content;
	num2 = (*stack)->next->content;
	num3 = (*stack)->next->next->content;
	printf("1: %d\n 2: %d\n 3: %d", num1, num2, num3);
	if(num1 > num2 && num3 > num2)
		sa_sb(stack);
	else if(num1 > num2 && num2 > num3)
	{
		sa_sb(stack);
		rra_rrb(stack);
	}
	else if(num1 > num2 && num2 < num3)
		ra_rb(stack);
	else if(num1 < num2 && num2 > num3)
	{
		sa_sb(stack);
		ra_rb(stack);
	}
	else if(num1 < num2 && num2 > num3)
		rra_rrb(stack);
	
}
