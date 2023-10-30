/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:33:14 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/30 16:33:40 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void lose_game(void)
{
    ft_printf("%s%s", COLOR_RED, "YOU LOOSE!");
    end_game();
}

void    move_sprit(t_map *map)
{
    map->player_img = mlx_xpm_file_to_image(map->mlx, map->p_direction,
			&map->img_width, &map->img_height);
	if (map->player_img == NULL)
		ft_error(10);
}

void	movements_on_screen(t_map *map)
{
	char	*mov;
		
	mov = ft_itoa(map->movements);
	ft_printf("%s\n", "MOV");
	mlx_string_put(map->mlx, map->mlx_win, 10, 10, 0x000000, "Movements: ");
	mlx_string_put(map->mlx, map->mlx_win, 60, 20, 0x0000000, mov);
	free(mov);
}