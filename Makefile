# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 12:54:40 by jde-agr           #+#    #+#              #
#    Updated: 2018/07/23 14:38:43 by jde-agr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jde-agr.filler

FLAGS = -W -Wall -Werror -Wextra

SRCS = srcs/*.c

OBJS = *.o

LIB = libft/libft.a

HEADERS = -I includes/ -I libft/includes

$(NAME):
	gcc $(FLAGS) $(SRCS) $(HEADERS) -c
	gcc $(FLAGS) $(OBJS) $(LIB) -o players/$(NAME)
	make clean

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
