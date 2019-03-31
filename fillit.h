/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuvalis <kkuvalis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:34:33 by nbethany          #+#    #+#             */
/*   Updated: 2019/03/31 17:23:22 by kkuvalis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"
# include <stdlib.h>
# define BUFF_SIZE 21

typedef struct		s_map
{
	char			**field;
	unsigned char	size;
}					t_map;

typedef struct		s_tetrimino
{
	int				height;
	int				width;
	char			**shape;
	char			letter;
}					t_tetrimino;

int					main(int argc, char **argv);
int					floor_sqrt(int number);
int					check(char *buf, int bytes);
int					check_order(char *buf);
t_list				*reader(int fd, t_list *tet_list);
t_tetrimino			*get_one_tet(char *buf, char letter);
t_map				*solver(t_list *tet);
t_map				*new_map(unsigned char size);
void				print_result(t_map *map);
void				free_map(t_map *map);
int					get_solution(t_map *map, t_list *tet);
int					can_place(t_map *map, t_tetrimino *tet, int x, int y);
t_list				*ft_lstreverse(t_list *alst);
void				test(char *buf, unsigned char *rectangle);
void				free_tetrimino(t_tetrimino *tet);
t_list				*free_tet_list(t_list *tet_list);
void				move_tet(t_map *map, t_tetrimino *tet, int x, int y);
void				del_tet(t_map *map, t_tetrimino *tet, int x, int y);
int					count_tet(t_list *tet_list);

#endif
