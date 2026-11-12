# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 13:52:02 by hkutlu            #+#    #+#              #
#    Updated: 2026/11/10 17:59:51 by hkutlu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_tail
SOURCES = main.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_atoi.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc -Wall -Wextra -Werror -I includes
RM = rm -f

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

all: $(NAME)
