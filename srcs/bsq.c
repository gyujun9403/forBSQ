/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:41 by mson              #+#    #+#             */
/*   Updated: 2021/03/17 20:41:32 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern char g_buff[BUFF_SIZE];

void	set_char(char c, int *size, int *line, t_info *info)
{
	if (c == '\n' && *line < info->row)
	{
		info->map[*line] = (char *)malloc(sizeof(char) * (*size) + 1);
		info->mall_map[1]++;
		ft_strcpy(info->map[*line], g_buff);
		info->map[*line][*size] = '\0';
		init_buff(g_buff);
		(*line)++;
		*size = 0;
	}
	else
	{
		g_buff[(*size)++] = c;
		map_cond_check(c, info);
	}
}

int		ft_malloc(int fd, t_info *info)
{
	int		line;
	char	c;
	int		size;

	size = 0;
	line = 0;
	info->map = (char **)malloc(sizeof(char *) * info->row);
	info->mall_map[0] = 1;
	while (read(fd, &c, 1))
	{
		if (line == info->row)
		{
			info->error = 1;
			return (info->error);
		}
		set_char(c, &size, &line, info);
	}
	if (info->mall_map[1] != info->row)
		info->error = ERROR;
	return (info->error);
}

int		ft_condition(int fd, t_info *info)
{
	int		index;
	char	c;
	int		size;
	int		leng;

	index = 0;
	size = 0;
	while ((leng = read(fd, &c, 1)) && c != '\n')
	{
		g_buff[size] = c;
		size++;
	}
	chk_condition(info, g_buff, size);
	if (info->error == ERROR)
		return (info->error);
	info->row = split_number(g_buff, size);
	info->condition = (char *)malloc(sizeof(char) * 4);
	info->mall_condition = 1;
	ft_strlcat(info->condition, g_buff + size - 3, 4);
	return (info->error);
}

void	set_map(int fd, t_info *info)
{
	int	index;
	int	j;

	index = -1;
	if (ft_condition(fd, info) == ERROR)
		return ;
	if (ft_malloc(fd, info) == ERROR)
		return ;
	if (ft_column(info) == ERROR)
		return ;
	info->board = (int **)malloc(sizeof(int *) * info->row);
	info->mall_board[0] = 1;
	while (++index < info->row)
	{
		info->board[index] = (int *)malloc(sizeof(int) * info->col);
		info->mall_board[1]++;
		j = 0;
		while (j < info->col)
			info->board[index][j++] = 0;
	}
}

void	free_info(t_info *info)
{
	int i;

	i = 0;
	if (info->mall_condition == 1)
		free(info->condition);
	if (info->mall_map[0] == 1)
	{
		while (i < info->mall_map[1])
			free(info->map[i++]);
		free(info->map);
	}
	i = 0;
	if (info->mall_board[0] == 1)
	{
		while (i < info->mall_board[1])
			free(info->board[i++]);
		free(info->board);
	}
}
