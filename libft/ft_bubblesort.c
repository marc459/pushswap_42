/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:02:15 by msantos-          #+#    #+#             */
/*   Updated: 2021/05/28 12:14:12 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_bubble_sort(int *messy_nums,int length)
{
	int c;
	int d;
	int swap;
	int *ret;

	c = 0;
	d = 0;
	ret = (int *)malloc(sizeof(int) * length);
	//ret = ft_memcpy((int *)ret, (int *)messy_nums, (size_t)length);
	while (c < length)
	{
		ret[c] = messy_nums[c];
		c++;
	}

	for (c = 0 ; c < length - 1; c++)
	{
		for (d = 0 ; d < length - c - 1; d++)
		{
			if (ret[d] > ret[d+1]) /* For decreasing order use '<' instead of '>' */
			{
				swap     = ret[d];
				ret[d]   = ret[d+1];
				ret[d+1] = swap;
			}
		}
	}
	return(ret);
}