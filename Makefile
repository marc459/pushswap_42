# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 17:37:32 by msantos-          #+#    #+#              #
#    Updated: 2021/06/13 18:30:37 by msantos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSHSWAP = push_swap

INCLUDES  = -I ./includes

CHECKER_SRCS = checker.c
PUSHSWAP_SRCS = push_swap.c srcs/pushswap/sort_3.c srcs/pushswap/sort_5.c srcs/pushswap/sort_100.c srcs/pushswap/stackfindnum.c
SRCS = srcs/shared/arg_manage.c srcs/shared/operations.c srcs/shared/utils.c srcs/shared/utils2.c srcs/shared/test.c
LIB_LIST = liblist/ft_lstadd_back.c liblist/ft_lstadd_front.c liblist/ft_lstclear.c liblist/ft_lstdelone.c \
			liblist/ft_lstiter.c liblist/ft_lstlast.c liblist/ft_lstmap.c liblist/ft_lstnew.c liblist/ft_lstsize.c
GNL = gnl/get_next_line60.c

CHECKER_O = $(CHECKER_SRCS:.c=.o)
PUSHSWAP_O = $(PUSHSWAP_SRCS:.c=.o)
SRCS_O = $(SRCS:.c=.o)
LIBFT_LIST_O = $(LIB_LIST:.c=.o)
GNL_O = $(GNL:.c=.o)

LIBFT = libft_42/libft.a

GCC = gcc
CFLAGS = -Wall -Wextra -Werror 
SANITIZE= -fsanitize=address



all: lib checker push_swap

%.o: %.c
	$(GCC) $(INCLUDES) -o $@ -c $^

checker: $(CHECKER_O) $(SRCS_O) $(LIBFT_LIST_O) $(GNL_O)
	$(GCC) $(INCLUDES) $(LIBFT) $(CHECKER_O) $(SRCS_O) $(LIBFT_LIST_O) $(GNL_O) -o $(CHECKER)

push_swap: $(CHECKER_O) $(SRCS_O) $(LIBFT_LIST_O) $(GNL_O)
	$(GCC) $(INCLUDES) $(LIBFT) $(PUSHSWAP_O) $(SRCS_O) $(LIBFT_LIST_O) $(GNL_O) -o $(PUSHSWAP)

lib:
	@make -C ./libft_42
	@make clean -C ./libft_42
normi:
	norminette *.c libft_42/*.c libft_42/*.h liblist/*.c liblist/*.h includes/*.h srcs/pushswap/*.c srcs/shared/*.c
clean:
	rm -rf $(PUSHSWAP_O) $(CHECKER_O) $(SRCS_O) $(LIBFT_LIST_O) $(GNL_O)

fclean:	clean
	rm -rf $(CHECKER) $(PUSHSWAP)
	@make fclean -C ./libft_42

re:     fclean all
