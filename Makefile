# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:58:02 by athonda           #+#    #+#              #
#    Updated: 2024/06/13 13:10:24 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftgetnextline.a

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	get_next_line.c get_next_line_utils.c

OBJS	=	$(patsubst %c,%o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

%o: %c get_next_line.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re