/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:38:23 by nbethany          #+#    #+#             */
/*   Updated: 2019/02/24 14:39:49 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check(char *buf)
{
    int j;
    int k;
    int hash_num;

    j = 0;
    k = 0;
    hash_num=0;
    while (k <= 3)
    {
        while (j <= 3)
        {
            if (!(ft_strchr(".#",buf[5*k + j])))
                return (0);
            if (buf[5*k + j] == '#')
                hash_num++;
            j++;
        }
        if (buf[5*k + j] != '\n')
            return (0);
        j = 0;
        k++;
    }
    if (hash_num == 4)
        return (1);
    else
        return (0);
}

tetrimino write_to_struct(char *buf)
{
    int i;
    int j;
    int width;
    int height;
    static char letter;
    tetrimino tet;

    i = 0;
    j = 0;
    width = 1;
    height = 1;
    letter = 'A';
    while (i <= 3)
    {
        while (j <= 3)
        {
            tet.grid[i][j] = buf[5 * i + j];
            if (tet.grid[i][j] == '#')
                tet.grid[i][j] = letter;
            j++;
        }
        j = 0;
        i++;
    }
    letter++;
    return(tet);
}

int reader(int fd)
{
    char buf[BUFF_SIZE];
    char slash;
    int i;

    i = 0;
    slash = 0;
    while ((i = read(fd, buf, BUFF_SIZE)) > 0)
    {
        if (check(buf))
            {
                write_to_struct(buf);
                i = read(fd, &slash, 1);
                    if (slash != '\n')
                        return (0);
            }
        else
            return (0);
    }
    return (1);
}