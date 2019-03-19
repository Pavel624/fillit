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
#include "./libft/libft.h"
#include <stdlib.h>
#define BUFF_SIZE 21
#define MAX_TETRIMINO 26

typedef struct tetrimino
{
    int height;
    int width;
    char shape[4][4];
    char letter;
    struct tetrimino *next;
} tetrimino;

int floorSqrt(int number);
int check(char *buf, int bytes);
int check_order(char *buf);
int reader (int fd, tetrimino *tet);
tetrimino *create_list(tetrimino *tet, char *buf, char letter);
void solver (tetrimino *tet);
char **new_map(char **map, unsigned char size);

#endif