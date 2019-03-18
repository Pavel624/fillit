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

int floorSqrt(int number)
{
    int start;
    int end;
    int ans;
    int mid;

    start = 1;
    end = number;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid * mid == number)
            return (mid);
        if (mid * mid < number)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return (ans + 1);
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
    if (buf[20] != '\n' && bytes == 21)
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
    return (sum == 6 || sum == 8 ? 1 : 0);
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

tetrimino *create_list(tetrimino *tet, char *buf, char letter)
{
    unsigned char rectangle[4];

    tetrimino_rectangle(buf, rectangle);
    tet->width = rectangle[1] - rectangle[0] + 1;
    tet->height = rectangle[3] - rectangle[2] + 1;
    tet->shape = 0;
    tet->letter = letter;
    return(tet);
}

int reader(int fd, tetrimino *tet)
{
    char buf[BUFF_SIZE];
    char letter;
    int bytes;

    letter = 'A';
    while ((bytes = read(fd, buf, BUFF_SIZE)) >= 20)
    {
        if (!check(buf, bytes) || (letter - 'A') >= 26)
            return (0);
        if (!(create_list(tet, buf, letter)))
            return (0);
        tet++;
        letter++;
    }
    return (1);
}