/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:55:11 by msantos-          #+#    #+#             */
/*   Updated: 2021/04/20 14:08:07 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned int	i;
	int				minus;
	long			value;

	value = 0;
	minus = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\f'
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		minus++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (str[i] <= 57 && str[i] >= 48)
	{
		value *= 10;
		value += str[i] - '0';
		i++;
	}
	if (minus == 1)
		value = value * -1;
	return (value);
}
