/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:29:24 by msantos-          #+#    #+#             */
/*   Updated: 2021/04/14 20:04:46 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

t_stack *ft_lstnew(int content)
{
	t_stack *elemento;

	if ((elemento = malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	
	elemento->content = content;
	elemento->next = NULL;
	
	return (elemento);
}
