# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmoswela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 14:55:39 by rmoswela          #+#    #+#              #
#    Updated: 2016/12/03 16:14:17 by rmoswela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = factrace

INC = ./include

LIB = libgmp.a

SRC = main.c ft_prime_factor.c ft_make_list.c

CFLAGS = -Wall -Werror -Wextra

GMPFLAGS = -lgmp

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) $(LIB) -I$(INC) -o $(NAME)

clean:
	rm -f *.o
fclean:
	rm -f factrace *.o

re: fclean all
