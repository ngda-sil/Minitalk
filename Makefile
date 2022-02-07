# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngda-sil <ngda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 19:21:55 by ngda-sil          #+#    #+#              #
#    Updated: 2022/02/02 16:33:49 by ngda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

NAMEBONUS = minitalk_bonus.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =  client.c serveur.c 

SRCSBONUS = client_bonus.c serveur_bonus.c
	
OBJS =  $(SRCS:.c=.o)

OBJSBONUS = ${SRCSBONUS:.c=.o}

PROG = client serveur 

PROGBONUS = client_bonus serveur_bonus

all: $(NAME)
	
$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf
	cp ft_printf/libftprintf.a $(NAME)
	ar rc $(NAME) $(OBJS) 
	$(CC) $(CFLAGS) -o client client.c $(NAME)
	$(CC) $(CFLAGS) -o serveur serveur.c $(NAME) 

bonus : ${OBJSBONUS}
	$(MAKE) -C ./ft_printf
	cp ft_printf/libftprintf.a $(NAMEBONUS)
	ar rc $(NAMEBONUS) $(OBJSBONUS) 
	$(CC) $(CFLAGS) -o client_bonus client_bonus.c $(NAMEBONUS)
	$(CC) $(CFLAGS) -o serveur_bonus serveur_bonus.c $(NAMEBONUS) 

clean:
	$(MAKE) clean -C ./ft_printf
	rm -f ${OBJS} ${OBJSBONUS}

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME) $(NAMEBONUS) $(OBJS) $(OBJSBONUS) $(PROG) $(PROGBONUS)

re: fclean all

.PHONY: all bonus clean fclean re
