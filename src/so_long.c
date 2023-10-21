/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:31:54 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/10/21 18:20:21 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
    t_map   map;
    check_arguments(argc, argv[1]);
    read_map(argv[1], &map);
    return (0);
}

// int main(void)
// {
//     printf("Hola\n");
//     return 0;
// }