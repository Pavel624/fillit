/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:38:23 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/31 21:02:47 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				floor_sqrt(int number)
{
	int			size;

	size = 2;
	while ((size * size) < number)
		size++;
	return (size);
}

/*
** Checks information in *buf.
** It must contain only ".#" and "\n" at the end of the line.
** Also there must be only 4 '#' and it must end with "\n" or "\0".
** If everything is OK returns a positive number.
*/

int				check(char *buf, int bytes)
{
	int			i;
	int			hash_num;

	i = 0;
	hash_num = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && !(ft_strchr(".#", buf[i])))
			return (0);
		if (buf[i] == '#' && hash_num++ > 4)
			return (0);
		if (i % 5 == 4 && buf[i] != '\n')
			return (0);
		i++;
	}
	if (ft_strlen(buf) == 21 && (buf[20] != '\n' && buf[20] != '\0'))
		return (0);
	if (!(check_order(buf)))
		return (0);
	return (bytes == 21 ? 1 : 2);
}

/*
** Checks ordder of tetramino in *buf. It must have 6 or 8 connections.
** If everything is OK returns a positive number.
*/

int				check_order(char *buf)
{
	int			i;
	int			sum;

	i = 0;
	sum = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 19 && buf[i + 1] == '#')
				sum++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				sum++;
			if (i + 5 <= 19 && buf[i + 5] == '#')
				sum++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				sum++;
		}
		i++;
	}
	return (sum == 6 || sum == 8);
}

/*
** Tries to read tetraminos one by one from file.
** If there's any error in a file then frees
** any allocated memory and returns NULL.
** If everything is OK returns a list with all tetraminos stored in it.
*/

t_list			*reader(int fd, t_list *tet_list)
{
	char		buf[BUFF_SIZE];
	char		letter;
	int			bytes;
	int			last;
	t_tetrimino	*tet_one;

	tet_one = NULL;
	letter = 'A';
	while ((bytes = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (bytes < 20)
			return (free_tet_list(tet_list));
		last = bytes;
		if (!check(buf, bytes) || (letter - 'A') >= 26)
			return (free_tet_list(tet_list));
		if (!(tet_one = get_one_tet(buf, letter)))
			return (free_tet_list(tet_list));
		ft_lstadd(&tet_list, ft_lstnew(tet_one, sizeof(t_tetrimino)));
		ft_memdel((void **)&tet_one);
		letter++;
	}
	if (last == 21 && bytes < 20)
		return (NULL);
	return (tet_list);
}
