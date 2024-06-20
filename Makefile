# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 11:58:02 by athonda           #+#    #+#              #
#    Updated: 2024/06/20 13:57:03 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libftgetnextline.a

NAME_B	=	libftgetnextline_bonus.a

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	get_next_line.c get_next_line_utils.c

SRCS_B	=	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	=	$(patsubst %c,%o,$(SRCS))

OBJS_B	=	$(patsubst %c,%o,$(SRCS_B))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

%o: %c get_next_line.h
	cc $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	ar rcs $@ $?

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean:
	rm -f $(OBJS) $(NAME) $(OBJS_B) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re