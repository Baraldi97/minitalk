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
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

PRINTF_DIR = ./printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
INC = -I. -I$(PRINTF_DIR)

SRC_DIR = src/mandatory
CLIENT_SRC = $(SRC_DIR)/client.c
SERVER_SRC = $(SRC_DIR)/server.c

BONUS_DIR = src/bonus
CLIENT_BONUS_SRC = $(BONUS_DIR)/client_bonus.c
SERVER_BONUS_SRC = $(BONUS_DIR)/server_bonus.c

all: $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(PRINTF):
	@make -C $(PRINTF_DIR)

$(NAME_CLIENT): $(CLIENT_SRC)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(INC) $(PRINTF) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_SRC)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(INC) $(PRINTF) -o $(NAME_SERVER)

bonus: $(PRINTF) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(CLIENT_BONUS_SRC)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(INC) $(PRINTF) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(SERVER_BONUS_SRC)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(INC) $(PRINTF) -o $(NAME_SERVER_BONUS)

clean:
	@make clean -C $(PRINTF_DIR)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re