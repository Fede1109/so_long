/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:54:59 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/18 17:03:46 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    read_map(char *argv)
{
    int fd;
    char    *map;
    char    *new_str;

    fd = open(argv, O_RDONLY);
    if (!fd || fd < 0)
        ft_error("1");
    while (1)
    {
        
    }
        
    
    
}

//TODO: Guardar mapa

/*
 TODO: Checkear mapa
 * SER RECTANGULAR
 * CERRADO/RODEADO DE MUROS
 * COMPROBAR QUE HAYA UN CAMINO VÁLIDO
    TODO: Checkear Elementos
    * UNA SOLA SALIDA
    * UNA SOLA POS INICIAL
    * AL MENOS 1 COLECCIONABLE
    TODO: Checkear bordes    
*/
//TODO: CONTADOR DE MOVIMIENTOS

//TODO: ASIGNACION TECLAS(movimiento y esc para salir)

//TODO: CONTADOR TOKENS
