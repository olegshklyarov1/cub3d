# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/03 17:31:09 by olshklya          #+#    #+#              #
#    Updated: 2026/11/03 17:31:33 by olshklya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -g -Wall -Wextra -Werror -std=gnu89

INCLUDES	= -I includes -I libft -I mlx

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= mlx
MLX			= $(MLX_DIR)/libmlx.a
LIBS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR		= src
OBJ_DIR		= obj

SRCS		= init/init_data.c\
					parsing/parse.c\
					parsing/check.c\
					parsing/utils.c\
					gnl/get_next_line.c\
					gnl/get_next_line_utils.c\
					main.c

SRC			= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS		= $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR) CFLAGS="-O3 -std=gnu89 -I.. "

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
