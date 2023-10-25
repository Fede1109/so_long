/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:42:19 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/25 13:54:06 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../minilibx_opengl/mlx.h"
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define PLAYER "./sprites/player.xpm"
# define COIN "./sprites/coin.xpm"
# define WALL "./sprites/wall.xpm"
# define FLOOR "./sprites/floor.xpm"
# define EXIT "./sprites/exit.xpm"
# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53

typedef struct s_map
{
    int     coins;
    int     coins_copy;
    int     n_players;
    int     exit;
    int     exit_copy;
    char    **map;
    char    **map_copy;
    size_t     map_width;
    size_t     map_height;    
    void    *mlx;
    void    *mlx_win;
    int     img_width;
    int     img_height;    
    // int     movements;
    // void    *player_img;
    // void    *coins_img;
    // void    *walls_img;
    // void    *exit_img;
    // void    *floor_img;
    
}t_map;

typedef struct s_player
{
    int     player_x;
    int     player_y;
    int     movements;
}t_player;

typedef struct s_img
{
    void    *player_img;
    void    *coins_img;
    void    *walls_img;
    void    *exit_img;
    void    *floor_img;
}t_img;



void    check_arguments(int argc, char *argv);
void    read_map(char *argv, t_map *map);
void    init_variables(t_map *map, t_player *player);
int     check_char_map(t_map *map);
void	check_rectangle(t_map *map);
void	count_elements(t_map *map, t_player *player);
void	check_elements_number(t_map *map);
int     check_border(t_map *map);
void	flood_fill(t_map *map, int column, int row);
void    check_path(t_map *map);
int	    end_game();
int	    win_game(t_map *map);
int		detect_key(int key_code, t_map *map, t_player *player);
void    coin_counter(t_map *map);
void	draw_map(t_map *map, t_img *images);
void    ft_error(int n);

#endif