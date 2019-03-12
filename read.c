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
    int i;
    int j;
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
    return (1);
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

int reader(int fd, tetrimino *tet)
{
    char buf[BUFF_SIZE + 1];
    int bytes;
    int i;
    char letter;

    i = 0;
    letter = 'A';
    ft_bzero(tet,80);

    while ((bytes = read(fd, buf, BUFF_SIZE)) > 19)
    {
        if (!check(buf, bytes))
            return (0);
        //tet[i] = write_to_struct(buf, letter++);
    }
    return (1);
}