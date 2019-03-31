/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addititonal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/31 17:31:55 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					can_place(t_map *map, t_tetrimino *tet, int x, int y)
{
	int				i;
	int				j;

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

int					get_solution(t_map *map, t_list *tet_list)
{
	int				x;
	int				y;
	t_tetrimino		*tet;

	y = 0;
	tet = (t_tetrimino *)(tet_list->content);
	while (y < map->size - tet->height + 1)
	{
		x = 0;
		while (x < map->size - tet->width + 1)
		{
			if (can_place(map, tet, x, y))
			{
				move_tet(map, tet, x, y);
				if (!(tet_list->next) || get_solution(map, tet_list->next))
					return (1);
				else
					del_tet(map, tet, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int					count_tet(t_list *tet_list)
{
	int				s;
	t_list			*tet;

	s = 0;
	tet = tet_list;
	while (tet)
	{
		s++;
		tet = tet->next;
	}
	return (s);
}

t_map				*solver(t_list *tet)
{
	t_map			*map;
	unsigned char	size;

	size = floor_sqrt(4 * count_tet(tet));
	map = new_map(size);
	while (!get_solution(map, tet))
	{
		size++;
		map = new_map(size);
	}
	return (map);
}
