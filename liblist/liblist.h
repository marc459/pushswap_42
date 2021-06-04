/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:27:10 by msantos-          #+#    #+#             */
/*   Updated: 2021/04/29 17:58:49 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
#define LIBLIST_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <strings.h>

typedef struct s_stack{
    int content;
    struct s_stack *next;
	struct s_stack *prev;
}				t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack  **alst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(int));
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void f(int));
t_stack		*ft_lstlast(t_stack *lst);
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(int));
t_stack *ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);

#endif