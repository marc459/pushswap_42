/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/08 21:37:18 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	defchunk(t_chunk *chunk, char **splited_args)
{
	chunk->n_args = ft_bidstrlen(splited_args);
	chunk->n_chunks = 5;
	if (120 < chunk->n_args && chunk->n_args < 250)
		chunk->n_chunks = 6;
	else if (250 <= chunk->n_args && chunk->n_args < 350)
		chunk->n_chunks = 8;
	else if (350 <= chunk->n_args && chunk->n_args < 450)
		chunk->n_chunks = 10;
	else if (chunk->n_args >= 450)
		chunk->n_chunks = 11;
	chunk->n_perchunk = chunk->n_args / chunk->n_chunks;
}

void	pushswap(t_stack **stack_a, t_stack **stack_b, char **splited_args)
{
	t_chunk	chunk;

	defchunk(&chunk, splited_args);
	if (chunk.n_args == 3)
		three_sort(stack_a);
	if (chunk.n_args == 4)
		five_sort(stack_a, stack_b);
	else if (chunk.n_args == 5)
		five_sort(stack_a, stack_b);
	else
		onehundred_sort(stack_a, stack_b, &chunk);
}

int	main(int argc, char **argv)
{
	char	**bidargs;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	bidargs = ft_split(concatenate_args(argv + 1, argc - 1), ' ');
	
	if (argc == 1 || (argc == 2 && ft_strcmp(ft_iteratespaces(argv[1]), "\0")))
		return (-1);
	if (!arg_checker(bidargs))
		str_error("Error\n");
	arg_save(&stack_a, bidargs);
	if (!already_sort(stack_a))
		pushswap(&stack_a, &stack_b, bidargs);
	print_stacks(stack_a, stack_b);
	free_double_ptr(bidargs);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
