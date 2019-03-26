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

void move_tet(map *map, tetrimino *tet, int x, int y)
{
    int i;
    int j;
    
    i = 0;
    while (i < tet->height)
    {
        j = 0;
        while (j < tet->width)
        {
            if (tet->shape[i][j] == '#')
                map->field[y + i][x + j] = '.';
            j++;
        }
        i++;
    }
}

int can_place(map *map, tetrimino *tet,int x, int y)
{
    int i;
    int j;

    i = 0;
    while (i < tet->height)
    {
        j = 0;
        while (j < tet->width)
        {
            if (map->field[y + i][x + j] != '.' && tet->shape[i][j] == '#')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int get_solution(map *map, tetrimino *tet)
{
    int x;
    int y;

    y = 0;
    while (map->size - tet->height + 1)
    {
        x = 0;
        while (map->size - tet-> width - 1)
        {
            if (can_place (map,tet,x,y))
            {
                move_tet(map, tet,x,y);
                if (get_solution(map, tet->next))
                    return (1);
                else
                    move_tet(map, tet,x,y);
            }
            x++;
        }
        y++;
    }
    return (0);
}

map *solver(tetrimino *tet)
{
    map *map;
    unsigned char size;
    // need a function to count all tetraminos
    size = floorSqrt(4 * 4);
    map = new_map(size);
    while (!get_solution(map, tet))
    {
        size++;
        map = new_map(size);
    }
    return (map);
}