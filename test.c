/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:52:04 by marcos            #+#    #+#             */
/*   Updated: 2021/05/29 18:56:36 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack_a,t_stack *stack_b)
{

	printf("STACK A\n");
	printf("-------------\n");
	if(stack_a)
		ft_lstiter(stack_a, print_node);
	printf("\n");
	printf("STACK B\n");
	printf("-------------\n");
	if(stack_b)
		ft_lstiter(stack_b, print_node);
	printf("\n");
}