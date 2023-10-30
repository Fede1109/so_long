/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:28:11 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/30 11:05:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	movements_on_screen(t_map *map)
{
	char	*mov = ft_itoa(map->movements);
	mlx_string_put(map->mlx, map->mlx_win, 10, 10, 000, "Movements");
	mlx_string_put(map->mlx, map->mlx_win, 10, 20, 000, mov);
	free(mov);
}