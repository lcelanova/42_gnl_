# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmunoz-f <lmunoz-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 21:40:24 by lmunoz-f          #+#    #+#              #
#    Updated: 2022/12/05 21:47:45 by lmunoz-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Wall -Wextra -Werror -Iinclude
SAN += -fsanitize=address
AR = ar

NAME = get_next_line.a

HEADER = get_next_line.h

SRC		 =	get_next_line.c \
			get_next_line.h \
			get_next_line_utlis.c \

			 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): libft $(OBJS) $(HEADER) $(LIBFT_HEADER)
	$(AR) -rcs $(NAME) $(OBJS)

debug: CFLAGS += -g
debug: fclean all
	$(CC) $(SAN) $(CFLAGS) test.c $(NAME) -o test

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus debug
