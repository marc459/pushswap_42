/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line60.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:35:59 by marcos            #+#    #+#             */
/*   Updated: 2021/04/19 14:46:19 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line60.h"

char *ft_strjoint(char *s, char c)
{
    char *dest;
    int i;
	
	i = 0;
    dest = malloc(ft_strlen(s) + 2);
    while (s[i] != '\0')
    {
        dest[i] = s[i];
        i++;
    }
    dest[i] = c;
    dest[i + 1] = '\0';
    free(s);
    return (dest);
}

int get_next_line(char **line)
{
    int ret;
    char buf[2];

    if (line == NULL || !(*line = ft_strdup("")))
        return (-1);
    while ((ret = read(0, buf, 1)) > 0)
    {
        if (buf[0] == '\n')
            break;
        *line = ft_strjoint(*line, buf[0]);
    }
    return (ret);
}