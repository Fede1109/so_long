# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 17:58:34 by fdiaz-gu          #+#    #+#              #
#    Updated: 2023/11/13 11:24:36 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./src
BONUS_DIR = ./src/bonus
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

all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@make -C $(MLX_PATH)
	@make bonus -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)	

B = .

.SILENT: $(BONUS_OBJS)
$(B_NAME): $(BONUS_OBJS)	
	@make -C $(MLX_PATH)
	@sleep 3
	@make bonus -C $(LIBFT_DIR)	
	@gcc $(CFLAGS) $(BONUS_OBJS) $(MINILIBX) $(LIBFT) -o $(B_NAME)
	@sleep 3	

bonus: $(B)

$(B): $(B_NAME)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT_A)

fclean: clean	
	@$(RM) $(NAME) $(B_NAME) $(BONUS_OBJS) $(OBJS)
	@make -C $(LIBFT_DIR) fclean	

re: fclean	
	@make all

.PHONY: all  clean fclean re