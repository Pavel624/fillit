/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:15:26 by nbethany          #+#    #+#             */
/*   Updated: 2019/02/24 14:15:38 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main (int argc, char **argv)
{
	tetrimino *tet;
	map *map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		return (-1);
	}
	if (!(tet = (tetrimino *)malloc(sizeof(tetrimino) * 27)) || 
				!(reader(open(argv[1], O_RDONLY), tet)))
	{
		ft_putstr("error\n");
		return (-1);
	}
	map = solver(tet);
	print_result(map);
	free_map(map);
	//free_tet(tet);
	return (0);
}