/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:14:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/18 14:04:30 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_arguments(int argc, char *argv)
{
    size_t len;
    
    if (argc != 2)
    {
        //TODO: Mostrar mensaje de error
        ft_error("Only two arguments please.");
    }
    else
    {
        len = strlen(argv);
        if ((ft_strncmp(".ber", argv + (len - 4), 4)))
        {
            //TODO: verificar que sea archivo .ber
            ft_error(1);    
        }
    }
}
//TODO: Hacer función error

void    ft_error(int n)
{
    if (n == 1)
        ft_printf("%sError\nNo such file or directory! \n", COLOR_RED);
    else if (n == 2)
		ft_printf("%sError\n Usage: ./so_long <filename>.ber \n", COLOR_RED);
    else if (n == 3)
        ft_printf("%sError\n Try create one valid map! \n", COLOR_RED);
    exit(n);
}

void    end_game()
{
    exit(0);
}