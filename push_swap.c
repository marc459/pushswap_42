/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:14:26 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/06 20:40:56 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_chunk{
	int n_args;
	int n_chunks;
	int n_perchunk;
	int minnum_chunk;
	int maxnum_chunk;
	
}				t_chunk;


int		*bidchartointarray(char **bid_char)
{
	int i;
	int *strnums;

	i = 0;
	strnums = malloc(sizeof(int) * ft_bidstrlen(bid_char));
	while(i < ft_bidstrlen(bid_char))
	{
		strnums[i] = ft_atoi(bid_char[i]);
		i++;
	}
	return(strnums);
}



void		defchunk(t_chunk *chunk,char **splited_args)
{
	chunk->n_args = ft_bidstrlen(splited_args);
	chunk->n_chunks = 5;
	if(120 < chunk->n_args && chunk->n_args < 250)
		chunk->n_chunks = 6;
	else if(250 <= chunk->n_args && chunk->n_args < 350)
		chunk->n_chunks = 8;
	else if(350 <= chunk->n_args && chunk->n_args <= 500)
		chunk->n_chunks = 10;
	else if(chunk->n_args > 500)
		chunk->n_chunks = 11;
	chunk->n_perchunk = chunk->n_args / chunk->n_chunks;
}

int		ft_bidintlen(int *arr)
{
	int	length;

	length = 0;
	while (arr[length])
		length++;
	return (length);
}

int			find_holdfirst(t_stack **stack_a,int minnum_chunk, int maxnum_chunk)
{
	int i;
	int hold_first;
	t_stack *tmp = *stack_a;

	i = 0;
	hold_first = 0;
	while(tmp != NULL && hold_first == 0)
	{
		if(tmp->content >= minnum_chunk && tmp->content <= maxnum_chunk)
			hold_first = i;
		tmp = tmp->next;
		i++;
	}
	return (hold_first);
}

int			find_holdlast(t_stack **stack_a,int minnum_chunk, int maxnum_chunk)
{
	int i;
	int hold_last;
	int *stack = linkedlisttointarray(*stack_a);
	t_stack *tmp = *stack_a;

	i = ft_lstsize(tmp) - 1;
	hold_last = 0;
	while(i >= 0)
	{
		hold_last++;
		if(stack[i] >= minnum_chunk && stack[i] <= maxnum_chunk)
			break;
		i--;
	}
	return (hold_last);
}

void		find_closestn_chunk(t_stack **stack,char selected_stack,int minnum_chunk, int maxnum_chunk)
{
	int hold_first;
	int hold_last;
	int i;

	i = 0;
	hold_first = find_holdfirst(stack,minnum_chunk,maxnum_chunk);
	hold_last = find_holdlast(stack,minnum_chunk,maxnum_chunk);
	if(hold_last < hold_first)
	{
		while(i < hold_last)
		{
			rra_rrb(stack);
			
			if(selected_stack == 'a')
				ft_putstr("rra\n");
			else
				ft_putstr("rrb\n");
			i++;
		}
	}
	else
	{
		while(i < hold_first)
		{
			ra_rb(stack);
			if(selected_stack == 'a')
				ft_putstr("ra\n");
			else
				ft_putstr("rb\n");
			i++;
		}
	}

}

void		pushswap(t_stack **stack_a,t_stack **stack_b,char **splited_args)
{
	
	t_chunk chunk;
	int *sorted_stack_a;
	int i;
	int x;

	i = 0;
	x = 0;
	defchunk(&chunk, splited_args);
	sorted_stack_a = ft_bubble_sort(linkedlisttointarray(*stack_a),chunk.n_args);
	
	if(chunk.n_args == 3)
		three_sort(stack_a);
	else if(chunk.n_args == 5)
		five_sort(stack_a,stack_b);
	else{
		//STACKA TO STACKB
		while(x < chunk.n_chunks)
		{
			chunk.minnum_chunk = sorted_stack_a[chunk.n_perchunk * x];
			chunk.maxnum_chunk = sorted_stack_a[chunk.n_perchunk * x] + chunk.n_perchunk - 1;
			while(i < chunk.n_perchunk)
			{
				find_closestn_chunk(stack_a,'a', chunk.minnum_chunk, chunk.maxnum_chunk);
				pa_pb(stack_b,stack_a);
				ft_putstr("pb\n");
				i++;
			}
			i = 0;
			x++;
		}
		chunk.minnum_chunk = chunk.maxnum_chunk + 1;

		while(ft_lstsize(stack_a[0]))
		{
			find_closestn_chunk(stack_a,'a', chunk.minnum_chunk, sorted_stack_a[ft_bidstrlen(splited_args)-1]);
			pa_pb(stack_b,stack_a);
			ft_putstr("pb\n");
		}
		//STACKB TO STACKA
		i = 1;
		while(ft_lstsize(stack_b[0]))
		{
			find_closestn_chunk(stack_b,'b', sorted_stack_a[chunk.n_args - i], sorted_stack_a[chunk.n_args - i]);
			pa_pb(stack_a,stack_b);
			ft_putstr("pa\n");
			i++;
			
		}
	}

}
char	*ft_iteratespaces(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
		

	return(str + i);
}

int     main(int argc, char **argv)
{
	char	*str_args;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

    if (argc == 1 || (argc == 2 && ft_strcmp(ft_iteratespaces(argv[1]),"\0")))
        return (-1);
	str_args = concatenate_args(argv + 1, argc - 1);
	if (!arg_checker(ft_split(str_args,' ')))
		str_error("Error1\n");
   	arg_save(&stack_a,str_args);
	if(!already_sort(stack_a))
		pushswap(&stack_a,&stack_b,ft_split(str_args,' '));

	print_stacks(stack_a,stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}