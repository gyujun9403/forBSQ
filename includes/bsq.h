/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:14:51 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 14:57:10 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>

# define BUFF_SIZE 1024
# define ERROR 1

typedef struct s_info
{
	int row;
	int col;
	int **board;
	int error;
	int mall_condition;
	int mall_map[2];
	int mall_board[2];
	char *condition;
	char **map;
}	t_info;

char g_buff[BUFF_SIZE];

int	split_number(char *condition, int size);
int ft_column(t_info *info);
void	set_map(int fd, t_info *l_map);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char	*ft_strcpy(char *dest, char *src);
void	init_buff(char *g_buff);
void manual_w1(t_info *info);
void manual_w2(t_info *info);
void prt_map(t_info *info);
void fill_board(t_info *info);
void free_info(t_info *info);
void	map_cond_check(char c, t_info *info);
void	row_check(int fd, t_info *info, int line);
void	error_isprintable(t_info *info, char c);
void chk_condition(t_info *info, char *buff, int size);

#endif
