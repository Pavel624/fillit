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
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input file\n");
		return (-1);
	}
	else 
	{
		fd = open(argv[1], O_RDONLY);
		if (reader(fd))
			ft_putstr("Valid\n");
		else
			ft_putstr("Not Valid\n");		
		close(fd);
	}
	return (0);
}
