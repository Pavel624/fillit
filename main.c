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
	tetrimino tet[MAX_TETRIMINO];
	//int tet_count;

	//tet_count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		return (-1);
	}
	if (!(reader(open(argv[1], O_RDONLY), tet)))
		ft_putstr("error\n");
	else
		ft_putstr("Valid\n");		
	//close();
	return (0);
}
