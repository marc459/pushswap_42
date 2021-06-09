# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 21:13:45 by msantos-          #+#    #+#              #
#    Updated: 2021/06/09 16:40:42 by msantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = push_swap

HEADER  = push_swap.h

CHECKER_SRCS = checker.c
PUSHSWAP_SRCS = push_swap.c srcs/pushswap/sort_3.c srcs/pushswap/sort_5.c srcs/pushswap/sort_100.c srcs/pushswap/stackfindnum.c

LIB_LIST = liblist/ft_lstadd_back.c liblist/ft_lstadd_front.c liblist/ft_lstclear.c liblist/ft_lstdelone.c \
			liblist/ft_lstiter.c liblist/ft_lstlast.c liblist/ft_lstmap.c liblist/ft_lstnew.c liblist/ft_lstsize.c
LIBFT = libft_42/libft.a
GNL = gnl/get_next_line60.c

SRCS = srcs/shared/arg_manage.c srcs/shared/operations.c srcs/shared/utils.c srcs/shared/utils2.c srcs/shared/test.c


CFLAGS = -Wall -Wextra -Werror 

SANITIZE= -fsanitize=address

GCC = gcc

all: fclean lib checker push_swap

checker:
	@$(GCC) $(CHECKER_SRCS) $(SRCS) $(LIB_LIST) $(GNL) $(LIBFT) -o $@
#$(FLAGS)

push_swap:
	@$(GCC) $(PUSHSWAP_SRCS) $(SRCS) $(LIB_LIST) $(GNL) $(LIBFT) -o $@
#$(FLAGS)

lib:
	@make -C ./libft_42
	@make clean -C ./libft_42
normi:
	norminette *.c
	norminette libft_42/*.c
	norminette liblist/*.c

clean:
	@rm -f $(CHECKER)

fclean:	clean
	rm -rf $(CHECKER) $(PUSHSWAP)
	@make fclean -C ./libft_42

re:     fclean all
