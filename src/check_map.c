/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:10 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/23 19:13:50 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 TODO: Checkear mapa
 * SER RECTANGULAR 
 * CERRADO/RODEADO DE MUROS
 * COMPROBAR QUE HAYA UN CAMINO VÁLIDO
	* Checkear Elementos
	* UNA SOLA SALIDA
	* UNA SOLA POS INICIAL
	* AL MENOS 1 COLECCIONABLE
	*: Checkear bordes
}
*/

//? CHECK ELEMENTOS. 0, 1, C, E, P
int	check_char_map(t_map *map)
{
	char	**aux_map;
	int		row;
	int		column;

	aux_map = map->map;
	column = 0;
	while (aux_map[column])
	{
		row = 0;
		while (aux_map[column][row])
		{
			if (aux_map[column][row] != '0' && aux_map[column][row] != '1' &&
				aux_map[column][row] != 'C' && aux_map[column][row] != 'E' &&
				aux_map[column][row] != 'P')
				ft_error(4);
			row++;
		}
		column++;
	}
	return (1);
}

//?Check si es rectángulo
void	check_rectangle(t_map *map)
{
	size_t	columns;

	columns = 0;
	map->map_width = 0;
	map->map_height = ft_strlen(map->map[columns]);
	while (map->map[columns])
	{
		map->map_width++;
		columns++;
	}
	columns = 0;
	while (map->map_width > columns)
	{
		if (map->map_height != ft_strlen(map->map[columns]))
			ft_error(5);
		columns++;
	}
}

//?Check si se complen las condiciones de los elementos
//TODO: DIVIDIR EN 2 FUNCIONES
void	check_elements_number(t_map *map)
{
	int		column;
	int		row;
	char	**aux_map;

	column = 0;
	aux_map = map->map;
	map->exit = 0;
	map->coins = 0;
	while (aux_map[column])
	{
		row = 0;
		while (aux_map[column][row])
		{
			if (aux_map[column][row] == 'C')
				map->coins++;
			if (aux_map[column][row] == 'E')			
				map->exit++;			
			if (aux_map[column][row] == 'P')
			{
				map->player_y = column;
				map->player_x = row;
				map->init_pos++;
			}
			row++;
		}
		column++;
	}
	if (map->coins < 1 || map->exit != 1 || map->init_pos != 1)
		ft_error(7);
	map->coins_copy = map->coins;
	map->exit_copy = map->exit;
}

//?Check del border
int	check_border(t_map *map)
{
	int		column;
	int		row;
	char	**aux_map;
	
	column = 0;
	aux_map = map->map;
	while (aux_map[column])
	{
		row = 0;
		while (aux_map[column][row])
		{
			if (aux_map[0][row] != '1'
				|| aux_map[column][0] != '1'
				|| aux_map[map->map_width - 1][row] != '1'
				|| aux_map[column][map->map_height - 1] != '1')
				ft_error(6);
			row++;
		}
		column++;
	}
	return (1);
}
