# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#              #
#    Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME :=			libftprintf.a

INCLUDE_DIR :=	./includes
L_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/*.c))
C_OBJS :=		$(patsubst %.c,%.o,$(wildcard ./srcs/ft_printf/*.c))

CFLAGS +=		-Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS +=		-L./ -lftprintf

.PHONY:			all clean fclean re

all: $(NAME)

$(NAME): $(L_OBJS) $(C_OBJS)
	ar rc $(NAME) $(L_OBJS) $(C_OBJS)
	ranlib $(NAME)

test: all main.o
	$(CC) $(CFLAGS) main.o -o test $(LDFLAGS)

clean:
	@- $(RM) $(C_OBJS) $(L_OBJS) main.o

fclean: clean
	@- $(RM) $(NAME) test

re: fclean all
