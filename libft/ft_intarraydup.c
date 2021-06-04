/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarraydup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 10:27:40 by msantos-          #+#    #+#             */
/*   Updated: 2021/05/28 11:43:33 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_intarraydup(int *n1)
{
	int		i;
	int	*ret;

	i = ft_len((long)n1);
	if (!i)
		return (ret);
	if (!(ret = (int *)malloc(sizeof(int) * i)))
		return (NULL);
   	ft_memcpy(ret, n1, i);
	return (ret);
}
