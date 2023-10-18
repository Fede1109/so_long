/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:14:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/17 15:01:45 by fdiaz-gu         ###   ########.fr       */
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
            ft_error("File must be .ber");    
        }
    }
}
//TODO: Hacer función error

void    ft_error(char *err)
{
    printf("%s%s\n", "\x1B[31m" ,err);
    exit(EXIT_FAILURE);
}

void    end_game()
{
    exit(0);
}