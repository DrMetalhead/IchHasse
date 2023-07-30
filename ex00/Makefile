# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricschmi <ricschmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 12:55:57 by ricschmi          #+#    #+#              #
#    Updated: 2023/07/30 21:26:11 by ricschmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

NAME = rush-02
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUD = includes/rush.h

SOURCES = src/ft_error_check.c \
			src/ft_rush.c \
			src/ft_utils.c \
			src/main.c \
			src/ft_free.c \
			src/ft_extra_mel.c \
			src/ft_read.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@cc -o $(NAME) $(CFLAGS) $(OBJECTS) -I $(INCLUD)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
	
