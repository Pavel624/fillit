/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitmebaby.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:36:56 by kkuvalis          #+#    #+#             */
/*   Updated: 2019/03/31 17:16:38 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check for minimum rectangle required for a tetramino.
** 0 - left 1 - right 2 - top 3 - bottom
*/

void				test(char *buf, unsigned char *rectangle)
{
	int				i;

	i = 0;
	rectangle[0] = 3;
	rectangle[1] = 0;
	rectangle[2] = 3;
	rectangle[3] = 0;
	while (i < 20)
	{
		if (buf[i] == '#')
		{
			if (i % 5 < rectangle[0])
				rectangle[0] = i % 5;
			if (i % 5 > rectangle[1])
				rectangle[1] = i % 5;
			if (i / 5 < rectangle[2])
				rectangle[2] = i / 5;
			if (i / 5 > rectangle[3])
				rectangle[3] = i / 5;
		}
		i++;
	}
}

void				free_tetrimino(t_tetrimino *tet)
{
	int				i;

	i = 0;
	while (i < tet->height)
	{
		ft_memdel((void **)&tet->shape[i]);
		i++;
	}
	ft_memdel((void **)&tet->shape);
	ft_memdel((void **)&tet);
}

t_list				*free_tet_list(t_list *tet_list)
{
	t_list			*tmp;

	while (tet_list)
	{
		free_tetrimino((t_tetrimino *)tet_list->content);
		tmp = tet_list->next;
		ft_memdel((void **)&tet_list);
		tet_list = tmp;
	}
	return (NULL);
}

t_tetrimino			*get_one_tet(char *buf, char letter)
{
	unsigned char	i;
	unsigned char	rectangle[4];
	t_tetrimino		*tet_one;

	tet_one = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	i = 0;
	test(buf, rectangle);
	tet_one->width = rectangle[1] - rectangle[0] + 1;
	tet_one->height = rectangle[3] - rectangle[2] + 1;
	tet_one->shape = (char **)malloc(tet_one->height * sizeof(char *));
	while (i < tet_one->height)
	{
		tet_one->shape[i] = (char *)malloc(tet_one->width * sizeof(char));
		ft_strncpy(tet_one->shape[i],
			buf + rectangle[0] + (i + rectangle[2]) * 5, tet_one->width);
		i++;
	}
	tet_one->letter = letter;
	return (tet_one);
}

t_list				*ft_lstreverse(t_list *alst)
{
	t_list			*node;
	t_list			*reversed;
	t_list			*tmp;

	if (!(alst) || !(alst->next))
		return (alst);
	node = alst->next;
	reversed = alst;
	reversed->next = NULL;
	while (node)
	{
		tmp = node;
		node = node->next;
		tmp->next = reversed;
		reversed = tmp;
	}
	return (reversed);
}
