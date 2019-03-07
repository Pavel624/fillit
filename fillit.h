/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:34:33 by nbethany          #+#    #+#             */
/*   Updated: 2019/02/24 14:35:18 by nbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"
#include <stdlib.h>
#define BUFF_SIZE 20

typedef struct tetrimino
{
    int height;
    int width;
    char grid[4][4];
    struct tetrimino *next;
} tetrimino;

int check(char *buf);
int reader (int fd);

#endif