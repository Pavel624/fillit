/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addititonal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/12 18:56:37 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **new_map(char **map, unsigned char size)
{
    int i, j;

    i = 0;
    if (!(map = (char **) malloc(sizeof(char *) * size + 1)))
        return NULL;
    while (i < size)
    {
        if (!(map[i] = (char *) malloc(sizeof(char) * size + 1)))
            return NULL;
        j = 0;
        while (j < size)
        {
            map[i][j] = '.';
            j++;
        }
        map[i][j] = 0;
        i++;
    }
    map[i] = 0;
    return (map);
}

//void solver(tetrimino *tet)
//{
  //  char **map;
  //  char **final;
   // unsigned char size;

  //  size = 0;
  //  map = NULL;
  //  map = new_map(map, floorSqrt(4 * 6));
  //  final = NULL;
//}