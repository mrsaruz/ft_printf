# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adruz-to <adruz-to@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 15:47:12 by adruz-to          #+#    #+#              #
#    Updated: 2025/07/13 18:31:12 by adruz-to         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC = cc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_putchar_pf.c ft_string_pf.c ft_pointer_pf.c \
	ft_number_pf.c ft_unint_pf.c ft_hexlower_pf.c ft_hexupper_pf.c \

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re