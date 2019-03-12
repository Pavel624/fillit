/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addititonal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:56:20 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/12 18:56:37 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

tetrimino *create_list(char **buf,int height, int width, char letter)
{
    tetrimino *tet;

    tet = ft_memalloc(sizeof(tetrimino));
    tet->height = height;
    tet->width = width;
    tet->letter = letter;
    tet->grid = buf;

    return (tet);
}

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
    return (ans);
}