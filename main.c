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
	//char letter;

	//int tet_count;

	//tet_count = 0;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		return (-1);
	}
	if (!(tet = (tetrimino *)malloc(sizeof(tetrimino) * 27)))
		{
			ft_putstr("error\n");
			return (0);
		}
	ft_bzero(tet,sizeof(tetrimino) * 27);
	if (!(reader(open(argv[1], O_RDONLY), tet)))
		ft_putstr("error\n");
	else
		ft_putstr("Valid\n");
	//close();
	for (int i = 1; i<= 26; i++)
		printf("%d - min %d - max %d\n",i,floorSqrt(4 * i),floorSqrt(4 * i) + 2);
	for (unsigned int i = 0; i<= sizeof(tet); i++)
	printf("%d height %d, width %d, letter %c, shape %d\n",i ,tet[i].height,tet[i].width,tet[i].letter,tet[i].shape);
	return (0);
}