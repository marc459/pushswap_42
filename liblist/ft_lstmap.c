/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:34:00 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/09 16:49:48 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(int))
{
	t_stack	*mapped;
	t_stack	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	mapped = NULL;
	while (lst != NULL)
	{
		tmp = ft_lstnew(lst->content);
		if (tmp == NULL)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, tmp);
		lst = lst->next;
	}
	return (mapped);
}
