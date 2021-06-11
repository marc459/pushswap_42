/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:54:15 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/11 17:50:38 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	exec_operation2(char *operation, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(operation, "sa\0"))
		sa_sb(stack_a);
	else if (ft_strcmp(operation, "sb\0"))
		sa_sb(stack_b);
	else if (ft_strcmp(operation, "ss\0"))
	{
		sa_sb(stack_a);
		sa_sb(stack_b);
	}
	else if (ft_strcmp(operation, "pa\0"))
		pa_pb(stack_a, stack_b);
	else if (ft_strcmp(operation, "pb\0"))
		pa_pb(stack_b, stack_a);
	else
		return (0);
	return (1);
}

void	exec_operation(char *operation, t_stack **stack_a, t_stack **stack_b)
{	
	if (ft_strcmp(operation, "ra\0"))
		ra_rb(stack_a);
	else if (ft_strcmp(operation, "rb\0"))
		ra_rb(stack_b);
	else if (ft_strcmp(operation, "rr\0"))
	{
		ra_rb(stack_a);
		ra_rb(stack_b);
	}
	else if (ft_strcmp(operation, "rra\0"))
		rra_rrb(stack_a);
	else if (ft_strcmp(operation, "rrb\0"))
		rra_rrb(stack_b);
	else if (ft_strcmp(operation, "rrr\0"))
	{
		rra_rrb(stack_a);
		rra_rrb(stack_b);
	}
	else if (!exec_operation2(operation, stack_a, stack_b))
		ft_putstr("Error\nWrite a valid operation:\n");
}

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;

	if (ft_lstsize(stack_b) > 0)
		return (0);
	while (stack_a != NULL)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		if (stack_a && (tmp->content >= stack_a->content))
			return (0);
	}
	return (1);
}

void	freeandresult(t_stack **stack_a, t_stack **stack_b)
{
	if (checker(*stack_a, *stack_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	char	*operation;
	char	**bidargs;
	char	*concatargs;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	operation = NULL;
	concatargs = concatenate_args(argv + 1, argc - 1);
	bidargs = ft_split(concatargs, ' ');
	if (argc == 1 || (argc == 2 && ft_strcmp(argv[1], "\0")))
		return (-1);
	if (!arg_checker(bidargs))
		str_error("Error\n");
	arg_save(&stack_a, bidargs);
	while (get_next_line(&operation) > 0 && !ft_strcmp(operation, "\0"))
	{
		exec_operation(operation, &stack_a, &stack_b);
		free(operation);
	}
	free(operation);
	free_double_ptr(bidargs);
	freeandresult(&stack_a, &stack_b);
	return (0);
}
