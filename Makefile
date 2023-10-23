# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:58:34 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/10/23 17:19:15 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
SRC = so_long.c utils.c read_map.c check_map.c check_path.c hooks.c draw_game.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
RM = rm -rf

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

NAME = so_long
MLX_PATH = minilibx_opengl/
MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit

GREEN='\033[32m'
GRAY='\033[2;37m'
ORANGE='\033[33m'
NONE='\033[0m'

all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@make -C $(MLX_PATH)
	@echo $(CURSIVE)$(GREEN) " - Making libft..." $(NONE)
	@make bonus -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GREEN) " - Compiling $(NAME)" $(NONE)
	@gcc $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)
	@echo $(CURSIVE)$(GREEN) " - Compiled" $(NONE)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT_A)

fclean: clean
	@echo $(CURSIVE)$(GREEN) " - Removing $(NAME)..." $(NONE)
	@$(RM) $(NAME) $(B_NAME) $(BONUS_OBJS) $(OBJS)
	@make -C $(LIBFT_DIR) fclean
	@echo $(CURSIVE)$(GREEN) " - Clean!" $(NONE)

re: fclean
	@echo $(CURSIVE)$(ORANGE) " - Compiling again..." $(NONE)
	@make all

.PHONY: all  clean fclean re