/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:29:24 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/09 16:46:26 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*elemento;

	elemento = malloc(sizeof(t_stack));
	if (elemento == NULL)
		return (NULL);
	elemento->content = content;
	elemento->next = NULL;
	return (elemento);
}
