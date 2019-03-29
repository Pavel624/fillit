/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:38:23 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/29 20:06:57 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int floorSqrt(int number)
{
    int size;

    size = 2;
    while (size * size < number)
        size++;
    return (size);
}

int check(char *buf, int bytes)
{
    char i;
    char j;
    int hash_num;

    i = 0;
    j = 0;
    hash_num = 0;
    while (i <= 3)
    {
        while (j <= 3)
        {
            if (!(ft_strchr(".#",buf[5*i + j])))
                return (0);
            if (buf[5*i + j] == '#' && hash_num++ > 4)
                return (0);
            j++;
        }
        if (buf[5*i + j] != '\n')
            return (0);
        j = 0;
        i++;
    }
    if (ft_strlen(buf) == 21 && (buf[20] != '\n' && buf[20] != '\0'))
        return (0);
    if (!(check_order(buf)))
        return (0);
    return (bytes == 21 ? 1 : 2);
}

int check_order(char *buf)
{
    int i;
    int j;
    int sum;
    char *new;

    i = 0;
    j = 0;
    sum = 0;
    while (i <= 3)
    {
        while (j <= 3)
        {
            if (buf[5*i + j] == '#')
            {
                if (5*i + j + 1 <= 19 && buf[5*i + j + 1] == '#')
                    sum++;
                if (5*i + j - 1 >= 0 && buf[5*i + j - 1] == '#')
                    sum++;
                if (5*i + j + 5 <= 19 && buf[5*i + j + 5] == '#')
                    sum++;
                if (5*i + j - 5 >= 0 && buf[5*i + j - 5] == '#')
                    sum++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    if (sum == 8)
    {
        i = 0;
        new = ft_strchr(buf, '#');
        if (new[i+1] == '#' && new[i+5] == '#' && new[i+6] == '#')
            sum = 6;
    }
    return (sum == 6 ? 1 : 0);
}

/*
** Check for minimum rectangle
** required for a piece.
** 0 - left 1 - right 2 - top 3 - bottom
*/

static void tetrimino_rectangle(char *buf, unsigned char *rectangle)
{
    int i;

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

void free_tetrimino(tetrimino *tet)
{
    int i;

    i = 0;
    while (i < tet->height)
    {
        ft_memdel((void **) &tet->shape[i]);
        i++;
    }
    ft_memdel((void **) &tet->shape);
    ft_memdel((void **) &tet);
}

t_list *free_tet_list(t_list *tet_list)
{
    t_list *tmp;

    while(tet_list)
    {
        free_tetrimino((tetrimino *)tet_list->content);
        tmp = tet_list->next;
        ft_memdel((void **)&tet_list);
        tet_list = tmp;
    }
    return (NULL);
}

tetrimino *get_one_tet(char *buf, char letter)
{
    unsigned char i;
    unsigned char rectangle[4];
    tetrimino *tet_one;

    tet_one = (tetrimino *)malloc(sizeof(tetrimino));
    i = 0;
    tetrimino_rectangle(buf, rectangle);
    tet_one->width = rectangle [1] - rectangle[0] + 1;
    tet_one->height = rectangle [3] - rectangle[2] + 1;
    tet_one->shape = (char **)malloc(tet_one->height * sizeof(char *));
    while (i < tet_one->height)
    {
        tet_one->shape[i] = (char *)malloc(tet_one->width * sizeof(char));
        ft_strncpy(tet_one->shape[i], buf + rectangle[0] + (i + rectangle[2]) * 5, tet_one->width);
        i++;
    }
    tet_one->letter = letter;
    return(tet_one);
}

t_list *ft_lstreverse(t_list *alst)
{
    t_list *node;
    t_list *reversed;
    t_list *tmp;

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

t_list *reader(int fd)
{
    char buf[BUFF_SIZE];
    char letter;
    int bytes;
    int last;
    tetrimino *tet_one;
    t_list *tet_list;

    tet_list = NULL;
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
        ft_lstadd(&tet_list, ft_lstnew(tet_one, sizeof(tetrimino)));
        ft_memdel((void **) &tet_one);
        letter++;
    }
    if (last == 21 && bytes < 20)
        return (free_tet_list(tet_list));
    return (tet_list);
}
