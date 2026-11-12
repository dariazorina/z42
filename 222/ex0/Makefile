# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 19:34:03 by hkutlu            #+#    #+#              #
#    Updated: 2026/11/09 14:51:30 by hkutlu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SOURCES = ft_display_file.c
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

