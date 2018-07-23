# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/23 12:54:40 by jde-agr           #+#    #+#              #
#    Updated: 2018/07/23 13:19:23 by jde-agr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = jde-agr.filler

FLAGS = -W -Wall -Werror -Wextra

SRCS = *.c

OBJS = *.o

LIB = libft/libft.a

HEADERS = filler.h -I libft/includes

$(NAME):
	gcc $(FLAGS) $(SRCS) $(HEADERS) -c
	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)

all : $(NAME)

clean :
	rm -rf $(NAME)
