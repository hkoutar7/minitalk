# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkoutar- <hkoutar-@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 01:32:21 by hkoutar-          #+#    #+#              #
#    Updated: 2023/05/06 01:32:24 by hkoutar-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

NAME = minitalk

all : $(NAME)

$(NAME) : client.c server.c helpful_func.c minitalk.h
	$(CC) $(CFLAGS) client.c helpful_func.c -o client
	$(CC) $(CFLAGS) server.c helpful_func.c -o server

bonus : client_bonus.c server_bonus.c helpful_func.c minitalk.h
	$(CC) $(CFLAGS) client_bonus.c helpful_func.c -o client
	$(CC) $(CFLAGS) server_bonus.c helpful_func.c -o server

clean :
	$(RM) client server

fclean : clean

re : fclean all

.PHONY : all clean fclean re
