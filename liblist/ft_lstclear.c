/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:31:54 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/09 16:48:03 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	ft_lstclear(t_stack **lst, void (*del)(int))
{
	t_stack	*current;
	t_stack	*next;

	if (del == 0 || *lst == 0)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
