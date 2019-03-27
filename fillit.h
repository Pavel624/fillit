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

typedef struct map
{
    char **field;
    unsigned char size;
} map;

typedef struct tetrimino
{
    int height;
    int width;
    char **shape;
    char letter;
} tetrimino;

int floorSqrt(int number);
int check(char *buf, int bytes);
int check_order(char *buf);
t_list *reader (int fd);
tetrimino *get_one_tet(char *buf, char letter);
map *solver (t_list *tet);
map *new_map(unsigned char size);
void print_result(map *map);
void free_map(map *map);
int get_solution(map *map, t_list *tet);
int can_place(map *map, tetrimino *tet,int x, int y);
void move_tet(map *map, tetrimino *tet, int x, int y);
t_list *ft_lstreverse(t_list *alst);

#endif