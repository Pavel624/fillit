/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:15:26 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/31 17:37:18 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_map	*map;
	int		fd;
	t_list	*tet_list;

	tet_list = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(argv[1], O_RDONLY);
	if (!(tet_list = reader(fd, tet_list)))
	{
		ft_putstr("error\n");
		exit(EXIT_SUCCESS);
	}
	close(fd);
	tet_list = ft_lstreverse(tet_list);
	map = solver(tet_list);
	print_result(map);
	free_map(map);
	free_tet_list(tet_list);
	return (0);
}
