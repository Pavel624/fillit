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

void print_result(map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_putstr(map->field[i]);
        ft_putstr("\n");
        i++;
    }
}

void free_map(map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_memdel((void **)map->field[i]);
        i++;
    }
    ft_memdel((void **)map);
}

map *new_map(unsigned char size)
{
    int i, j;

    map *map;

    i = 0;
    if (!(map = malloc(sizeof(map))))
        return (NULL);
    map->size = size;
    while (i < size)
    {
        if (!(map->field[i] = (char *) malloc(sizeof(char) * size)))
            return (NULL);
        j = 0;
        while (j < size)
        {
            map->field[i][j] = '.';
            j++;
        }
        i++;
    }
    return (map);
}

map *solver(tetrimino *tet)
{
    map *map;
  //  char **final;
    unsigned char size;
    // need a function to count all tetraminos
    size = floorSqrt(4 * 6);
    map = new_map(size);
    while (!get_solve(tet,map))
    {
        size++;
        map = new_map(size);
    }
    return (map);
  //  map = new_map(map, floorSqrt(4 * 6));
  //  final = NULL;
}