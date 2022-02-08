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

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = ./srcs/client.c
OBJS_C = ${SRC_C:.c=.o}

SRC_S = ./srcs/serveur.c
OBJS_S = ${SRC_S:.c=.o}

SRC_C_B = ./srcs_bonus/client_bonus.c
OBJS_C_B = ${SRC_C_B:.c=.o}

SRC_S_B = ./srcs_bonus/serveur_bonus.c
OBJS_S_B = ${SRC_S_B:.c=.o}

LIB = -lftprintf
LIB_PATH = -I ./ft_printf -L lib


all: ftprintf client serveur

ftprintf : 
	$(MAKE) -C ./ft_printf

client : $(OBJS_C)
	 $(CC) $(CFLAGS) $(LIB) -o $@ $^ ./ft_printf/ft_printf.h$(LIB_PATH)
serveur : $(OBJS_S)
	 $(CC) $(CFLAGS) $(LIB) -o $@ $^ $(LIB_PATH)	


bonus : client_bonus serveur_bonus ftprintf

client_bonus : $(OBJS_C_B)
	$(CC) $(CFLAGS) $(LIB) -o $@ $^ $(LIB_PATH)

serveur_bonus : $(OBJS_S_B)
	 $(CC) $(CFLAGS) $(LIB) -o $@ $^ $(LIB_PATH)


clean:
	$(MAKE) clean -C /ft_printf
	rm -f ${OBJS_C} ${OBJS_S} {OBJS_C_B} ${OBJS_S_B}

fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f serveur client serveur_bonus client_bonus

re: fclean all

.PHONY: all bonus clean fclean re
