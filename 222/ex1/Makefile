# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 20:41:12 by hkutlu            #+#    #+#              #
#    Updated: 2026/11/09 14:53:00 by hkutlu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_cat
SOURCES = ft_cat.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc -Wall -Wextra -Werror
RM = rm -f

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

all: $(NAME)

