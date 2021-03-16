/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:14:51 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/16 21:12:09 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 1024

typedef struct s_info
{
	int row;
	int col;
	char *condition;
	char **map;
	int **board;
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

#endif
