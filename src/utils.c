/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:14:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/23 13:05:14 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_arguments(int argc, char *argv)
{
    size_t len;
    
    if (argc != 2)
    {
        //*: Mostrar mensaje de error
        ft_error(8);
    }
    else
    {
        len = ft_strlen(argv);
        if(len < 4)
            ft_error(1);
        if ((ft_strncmp(".ber", argv + (len - 4), 4)))
        {
            //*: verificar que sea archivo .ber
            ft_error(1);            
        }
    }
}
//TODO: Acabar función error

void    ft_error(int n)
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
        ft_printf("%sError\nKey data in map is missing or incorrect \n", COLOR_RED);
    else if (n == 8)
        ft_printf("%sError\nTwo arguments please \n", COLOR_RED);
    else if (n == 9)
        ft_printf("%sError\nMap has not a valid path\n", COLOR_RED);
    else if (n == 10)
        ft_printf("%sError\nFailed to open the image.\n", COLOR_RED);
    exit(n);
}

void    end_game()
{
    exit(0);
}