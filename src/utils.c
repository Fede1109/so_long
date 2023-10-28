/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:14:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/28 19:10:10 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_arguments(int argc, char *argv)
{
	size_t	len;

	if (argc != 2)
		ft_error(8);
	else
	{
		len = ft_strlen(argv);
		if (len < 4)
			ft_error(1);
		if ((ft_strncmp(".ber", argv + (len - 4), 4)))			
			ft_error(1);
	}
}
//TODO: FUNCION LIBERAR MAPA

void	ft_error(int n)
{
	if (n == 1)
		ft_printf("%sError\nNo such file or directory! \n", COLOR_RED);
	else if (n == 2)
		ft_printf("%sError\nUsage: ./so_long <filename>.ber \n", COLOR_RED);
	else if (n == 3)
		ft_printf("%sError\nTry create one valid map! \n", COLOR_RED);
	else if (n == 4)
		ft_printf("%sError\nMap has invalid characters! \n", COLOR_RED);
	else if (n == 5)
		ft_printf("%sError\nMap is not a rectangle! \n", COLOR_RED);
	else if (n == 6)
		ft_printf("%sError\nMap is not surrounded by walls! \n", COLOR_RED);
	else if (n == 7)
		ft_printf("%sError\nKey data in map is missing or incorrect \n",
			COLOR_RED);
	else if (n == 8)
		ft_printf("%sError\nTwo arguments please \n", COLOR_RED);
	else if (n == 9)
		ft_printf("%sError\nMap has not a valid path\n", COLOR_RED);
	else if (n == 10)
		ft_printf("%sError\nFailed to open the image.\n", COLOR_RED);
	exit(n);
}

int	end_game(void)
{
	exit (0);
	return (0);
}

int	win_game(t_map *map)
{
	if (map->coins == 0)
	{
		ft_printf("%s%s\n", COLOR_GREEN, "CONGRATULATIONS! You win.");
		exit (0);
	}
	else
		ft_printf("%s%s\n", COLOR_BLUE, "You didn`t find all the coins!");
	return (0);
}

void	coin_counter(t_map *map)
{
	map->coins--;
	if (map->coins == 0)
		ft_printf("%c%s%s%c", '\n', COLOR_GREEN,
			"You found all the coins! Find the exit", '\n');
}
