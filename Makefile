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
SRC_S = ./srcs/serveur.c

SRC_C_B = ./srcs_bonus/client_bonus.c
SRC_S_B = ./srcs_bonus/serveur_bonus.c

LIB = -L./ft_printf/ -lftprintf
INCL = -I./ft_printf/ -I../ft_printf/

all:  client serveur
bonus :  client_bonus serveur_bonus

ftprintf :
	make -C ./ft_printf/

client : ftprintf
	$(CC) $(CFLAGS) $(INCL) $(LIB) $(LIB_PATH) $(SRC_C) -o $@
serveur : ftprintf
	$(CC) $(CFLAGS) $(INCL) $(LIB) $(LIB_PATH) $(SRC_S) -o $@


client_bonus : ftprintf
	$(CC) $(CFLAGS) $(INCL) $(LIB) $(LIB_PATH) $(SRC_C_B) -o $@
serveur_bonus : ftprintf
	$(CC) $(CFLAGS) $(INCL) $(LIB) $(LIB_PATH) $(SRC_S_B) -o $@


clean:
	$(MAKE) clean -C ./ft_printf/

fclean: clean
	rm -f serveur client serveur_bonus client_bonus

re: fclean all

.PHONY: all bonus clean fclean re
