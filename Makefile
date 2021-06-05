# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 21:13:45 by msantos-          #+#    #+#              #
#    Updated: 2021/06/05 22:21:10 by msantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = push_swap

HEADER  = push_swap.h

CHECKER_SRCS = checker.c
PUSHSWAP_SRCS = push_swap.c order_3.c

LIB_LIST = liblist/ft_lstadd_back.c liblist/ft_lstadd_front.c liblist/ft_lstclear.c liblist/ft_lstdelone.c \
			liblist/ft_lstiter.c liblist/ft_lstlast.c liblist/ft_lstmap.c liblist/ft_lstnew.c liblist/ft_lstsize.c
LIBFT = libft_42/libft.a
GNL = gnl/get_next_line60.c

SRCS = arg_manage.c operations.c utils.c push_swap2.c


CFLAGS = -Wall -Wextra -Werror 

SANITIZE= -fsanitize=address

GCC = gcc

all: fclean lib checker push_swap

checker:
	@$(GCC) $(CFLAGS) $(CHECKER_SRCS) $(SRCS) $(LIB_LIST) $(GNL) $(LIBFT) test.c -o $@
#$(FLAGS)

push_swap:
	@$(GCC) $(PUSHSWAP_SRCS) $(SRCS) $(LIB_LIST) $(GNL) $(LIBFT) test.c -o $@
#$(FLAGS)

lib:
	@make -C ./libft_42
	@make clean -C ./libft_42

clean:
	@rm -f $(CHECKER)

fclean:	clean
	rm -rf $(CHECKER) $(PUSHSWAP)
	@make fclean -C ./libft_42

re:     fclean all
