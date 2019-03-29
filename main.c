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
	map *map;
	int fd;
	t_list *tet_list;

	tet_list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		return (-1);
	}
	if (!(tet_list = reader(fd = open(argv[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (-1);
	}
	close(fd);
	tet_list = ft_lstreverse(tet_list);
	map = solver(tet_list);
	print_result(map);
	free_map(map);
	free_tet_list(tet_list);
	return (0);
}