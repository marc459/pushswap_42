/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/07 22:00:25 by msantos-         ###   ########.fr       */
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
	if (chunk.n_args == 2)
		two_sort(stack_a);
	else if (chunk.n_args == 3)
		three_sort(stack_a);
	else if (chunk.n_args == 4)
		five_sort(stack_a, stack_b);
	else if (chunk.n_args == 5)
		five_sort(stack_a, stack_b);
	else
		onehundred_sort(stack_a, stack_b, &chunk);
}

int	main(int argc, char **argv)
{
	char	**bidargs;
	char	*concatargs;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && ft_strcmp(ft_iteratespaces(argv[1]), "\0")))
		return (-1);
	concatargs = concatenate_args(argv + 1, argc - 1);
	bidargs = ft_split(concatargs, ' ');
	free(concatargs);
	if (!arg_checker(bidargs))
		str_error("Error\n");
	arg_save(&stack_a, bidargs);
	if (!already_sort(stack_a))
		pushswap(&stack_a, &stack_b, bidargs);
	free_double_ptr(bidargs);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
