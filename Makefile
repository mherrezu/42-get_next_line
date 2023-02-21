# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:28:13 by mherrezu          #+#    #+#              #
#    Updated: 2023/02/15 12:20:01 by mherrezu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o) 

CC = cc

CFLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=10 -g

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
			$(CC) -c $(CFLAGS) $(SRCS)
			ar crs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean: 	clean
						$(RM) $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re