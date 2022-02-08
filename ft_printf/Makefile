# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 19:21:55 by ngda-sil          #+#    #+#              #
#    Updated: 2022/02/07 20:24:55 by ngda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c \
		ft_print_hex.c \
		ft_print_ptr.c \
		ft_print_unsigned.c \
		ft_printchar.c \
		ft_printnbr.c \
		ft_printstr.c 

OBJS = ${SRCS:.c=.o}

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	cp ./libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJS) 

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -f ${OBJS} 

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
