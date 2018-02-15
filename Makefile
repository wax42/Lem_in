# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 01:08:15 by vguerand          #+#    #+#              #
#    Updated: 2018/02/13 01:53:48 by vguerand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
PATH_SRC = ./
PATH_INC = ./libft/includes/ -I ./includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ./includes/lem_in.h

SRC =  ft_crea_room.c main.c ft_check_htag.c ft_crea_tube.c utils.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -L libft/ -lft

.PHONY: clean fclean re all

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
