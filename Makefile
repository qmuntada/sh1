# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/27 20:27:42 by frcugy            #+#    #+#              #
#    Updated: 2015/06/14 16:52:37 by frcugy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_minishell1

NAMEBASE	=	$(shell basename $(NAME))

CC			=	gcc -Wall -Wextra -Werror -Iincludes

FLAGS		= -Wall -Wextra -Werror

LIBS		=

SRCBASE		=	\
				src/main.c \
				src/env_list.c \
				src/core.c \
				src/check_exec.c \
				src/parse.c \
				src/ft_set_env.c \
				src/ft_unset_env.c \
				src/ft_cd.c \
				src/ft_exit.c \
				src/ft_cd2.c

SRCS		=	$(SRCBASE)

OBJS		=	$(SRCBASE:.c=.o)

.SILENT:

all: $(NAME)
	echo "\033[38;5;44m✅  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME): $(OBJS) includes/$(NAME).h ./libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
	echo -en "\r\033[38;5;22m✅  MAKE   $(NAMEBASE)\033[0m\033[K"

%.o: %.c $(NAME).h
	$(CC) $(FLAGS) -c $< -o $@

./libft/libft.a:
	make -C libft/ fclean
	make -C libft/

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C libft/ fclean
	if [[ `rm $(OBJS) &> /dev/null 2>&1; echo $$?` == "0" ]]; then           \
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";      \
		else                                                                     \
		printf "\r";                                                         \
		fi

fclean: clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) plz wait ...\033[0m\033[K"
	make -C libft/ fclean
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then           \
		echo -en "\r\033[38;5;124m🔘  FCLEAN $(NAMEBASE)\033[0m\033[K";      \
		else                                                                     \
		printf "\r";                                                         \
		fi

re:			fclean all ./libft/libft.a

.PHONY:		fclean clean re
