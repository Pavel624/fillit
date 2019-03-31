/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onemoretime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:57:44 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/03/31 17:35:55 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_result(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->field[i]);
		ft_putstr("\n");
		i++;
	}
}

void		free_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&map->field[i]);
		i++;
	}
	ft_memdel((void **)&map->field);
	ft_memdel((void **)&map);
}

t_map		*new_map(unsigned char size)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	if (!(map = malloc(sizeof(map))))
		return (NULL);
	if (!(map->field = (char **)malloc(size * sizeof(char *))))
		return (NULL);
	map->size = size;
	while (i < size)
	{
		if (!(map->field[i] = (char *)malloc(sizeof(char) * size)))
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

void		move_tet(t_map *map, t_tetrimino *tet, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < tet->height)
	{
		j = 0;
		while (j < tet->width)
		{
			if (tet->shape[i][j] == '#')
				map->field[y + i][x + j] = tet->letter;
			j++;
		}
		i++;
	}
}

void		del_tet(t_map *map, t_tetrimino *tet, int x, int y)
{
	int		i;
	int		j;

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
