# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 11:56:39 by avan-ni           #+#    #+#              #
#    Updated: 2018/07/25 11:56:58 by avan-ni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avan-ni.filler

FLAGS = -W -Wall -Werror -Wextra

SRCS = srcs/*.c

OBJS = *.o

LIB = libft/libft.a

HEADERS = -I includes/ -I libft/includes

$(NAME):
	make fclean
	make fclean -C libft/
	make -C libft/
	make clean -C libft/
	gcc $(FLAGS) $(SRCS) $(HEADERS) -c
	gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	make clean

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf libft/libft.a
	rm -rf $(NAME)

re : fclean all
