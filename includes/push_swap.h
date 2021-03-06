/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:06:51 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/11 17:22:41 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#		ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft_42/libft.h"
# include "../liblist/liblist.h"
# include "../gnl/get_next_line60.h"

typedef struct s_chunk{
	int	n_args;
	int	n_chunks;
	int	n_perchunk;
	int	minnum_chunk;
	int	maxnum_chunk;
}				t_chunk;

//PUSSWAP
int		*bid_chartoint(char **bid_char);
void	two_sort(t_stack **stack);
void	three_sort(t_stack **stack);
void	three_sort_2(t_stack **stack);
void	five_sort(t_stack **stack_a, t_stack **stack_b);
void	find_closestn_chunk(t_stack **stack, char selected_stack,
			int minnum_chunk, int maxnum_chunk);
int		find_holdfirst(t_stack **stack_a, int minnum_chunk, int maxnum_chunk);
int		find_holdlast(t_stack **stack_a, int minnum_chunk, int maxnum_chunk);
void	onehundred_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *chunk);
void	onehundred_sort2(t_stack **stack_a,
			t_stack **stack_b, t_chunk *chunk, int	*s_stack_a);
//CHECKER
void	freeandresult(t_stack **stack_a, t_stack **stack_b);
//UTILS.C
int		str_error(char *s);
int		str_isnumber(char *str);
void	print_node(int content);
void	free_stack(t_stack **stack);
int		ft_bidstrlen(char **arr);
int		*linkedlisttointarray(t_stack *lst);
int		already_sort(t_stack *stack);
char	*ft_iteratespaces(char *str);
int		ft_bidintlen(int *arr);
int		*bidchartointarray(char **bid_char);

//ARG_MANAGEMENT.C
int		arg_checker(char **splited_args);
void	arg_save(t_stack **stack_a, char **splited_args);
char	*concatenate_args(char **args, int size);
void	free_double_ptr(char **s);

//OPERATIONS
void	sa_sb(t_stack **stack_a);
void	pa_pb(t_stack **stack1, t_stack **stack2);
void	ra_rb(t_stack **stack);
void	rra_rrb(t_stack **stack);

//TEST
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

#		endif