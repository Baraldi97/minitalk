# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/23 10:36:01 by marvin            #+#    #+#              #
#    Updated: 2025/12/23 10:36:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
INC = -I. -I$(PRINTF_DIR)

SRC_DIR = src/mandatory
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

all: $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME_CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(INC) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(INC) $(PRINTF) -o $(NAME_SERVER)

clean:
	@make clean -C $(PRINTF_DIR)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re