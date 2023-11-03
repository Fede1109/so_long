# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:58:34 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/11/03 10:41:04 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
BONUS_DIR = ./src/bonus/
SRC = so_long.c utils.c read_map.c check_map.c check_path.c hooks.c draw_game.c
BONUS = so_long_bonus.c utils_bonus.c utils_2_bonus.c read_map_bonus.c hooks_bonus.c draw_game_bonus.c check_path_bonus.c check_map_bonus.c


OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3
AR = ar
ARFLAGS = rcs
RM = rm -rf
B_NAME = so_long_bonus

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

B = .

.SILENT: $(BONUS_OBJS)
$(B_NAME): $(BONUS_OBJS)
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@make -C $(MLX_PATH)
	@echo $(CURSIVE)$(GREEN) " - Making libft..." $(NONE)
	@sleep 3
	@make bonus -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GREEN) " - Compiling $(B_NAME)" $(NONE)
	@gcc $(CFLAGS) $(BONUS_OBJS) $(MINILIBX) $(LIBFT) -o $(B_NAME)
	@sleep 3
	@echo $(CURSIVE)$(GREEN) " - Compiled" $(NONE)

bonus: $(B)

$(B): $(B_NAME)

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