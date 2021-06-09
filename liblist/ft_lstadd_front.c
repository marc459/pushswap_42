/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:29:07 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/09 16:48:44 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	ft_lstadd_front(t_stack **alst, t_stack *new)
{
	if (alst[0])
	{
		new->next = alst[0];
		alst[0] = new;
	}
	else
	{
		new->next = NULL;
		alst[0] = new;
	}
}
