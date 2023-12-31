/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:42:19 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/13 11:51:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define COLOR_NORMAL "\033[0m"
# define PLAYER "./sprites/down.xpm"
# define COIN "./sprites/coin.xpm"
# define WALL "./sprites/wall.xpm"
# define ENEMY "./sprites/enemy.xpm"
# define FLOOR "./sprites/floor.xpm"
# define EXIT "./sprites/exit.xpm"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_map
{
	int			coins;
	int			coins_copy;
	int			coins_copy_2;
	int			n_players;
	int			enemies;
	int			player_copy;
	int			exit;
	int			exit_x;
	int			exit_y;
	int			status;
	char		**map;
	char		**map_copy;
	char		**map_copy_2;
	size_t		map_width;
	size_t		map_height;
	void		*mlx;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	int			player_x;
	int			player_y;
	int			movements;
	void		*player_img;
	void		*coins_img;
	void		*walls_img;
	void		*exit_img;
	void		*floor_img;
	void		*enemy_img;
	void		*p_direction;
}t_map;

void	check_arguments(int argc, char *argv, t_map *map);
void	read_map(char *argv, t_map *map);
void	init_variables(t_map *map);
int		check_char_map(t_map *map);
void	check_rectangle(t_map *map);
void	count_elements(t_map *map);
void	check_elements_number(t_map *map);
int		check_border(t_map *map);
void	assign_exit(int column, int row, t_map *map);
void	flood_fill_from_player(t_map *map, int column, int row);
void	flood_fill_from_exit(t_map *map, int column, int row);
void	check_path(t_map *map);
int		end_game(void);
int		win_game(t_map *map);
int		detect_key(int key_code, t_map *map);
void	movements_on_screen(t_map *map);
void	coin_counter(t_map *map);
void	lose_game(void);
void	draw_map(t_map *map);
void	move_sprit(t_map *map);
void	ft_error(int n, t_map *map);
void	free_map(t_map *map);

#endif