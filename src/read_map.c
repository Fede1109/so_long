/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:54:59 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/13 11:11:09 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fill_map(t_map *map, char *str)
{
	map->map = ft_split(str, '\n');
	map->map_copy = ft_split(str, '\n');
	map->map_copy_2 = ft_split(str, '\n');
	map->status = 1;
}

void	read_map(char *argv, t_map *map)
{
	int		fd;
	char	*map_str;
	char	*map2_str;
	char	*aux_str;

	fd = open(argv, O_RDONLY);
	if (!fd || fd < 0)
		ft_error(1, map);
	map_str = ft_strdup("");
	while (1)
	{
		aux_str = get_next_line(fd);
		if (!aux_str)
		{
			map->status = 0;
			break ;
		}
		map2_str = ft_strdup(map_str);
		free(map_str);
		map_str = ft_strjoin_gnl(map2_str, aux_str);
		free(aux_str);
	}
	fill_map(map, map_str);
	free(map_str);
}
