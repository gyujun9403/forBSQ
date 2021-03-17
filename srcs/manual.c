/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:11:30 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 23:36:00 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern char g_buff[BUFF_SIZE];

void	stdin_condition(t_info *info)
{
	int		readin;
	int		leng;
	char	w;

	leng = 0;
	while ((readin = read(0, &w, 1)) > 0 && w != '\n' && w != '\0')
	{
		chk_word(w, info);
		g_buff[leng++] = w;
	}
	chk_condition(info, g_buff, leng);
	if (info->error == ERROR)
	{
		info->error = STDIN_CONDI_ERROR;
		return ;
	}
	info->row = split_number(g_buff, leng);
	info->condition = (char *)malloc(4);
	info->mall_condition = 1;
	ft_strlcat(info->condition, g_buff + leng - 3, 4);
	stdin_map(info);
}

void	stdin_map(t_info *info)
{
	int		i;
	int		leng;
	int		readin;
	char	w;

	i = 0;
	info->map = (char **)malloc(sizeof(char *) * info->row);
	info->mall_map[0] = 1;
	while (i < info->row)
	{
		leng = 0;
		while ((readin = read(0, &w, 1)) > 0 && w != '\n' && w != '\0')
		{
			map_cond_check(w, info);
			g_buff[leng++] = w;
		}
		info->map[i] = (char *)malloc(sizeof(char) * leng + 1);
		info->mall_map[1]++;
		ft_strlcat(info->map[i], g_buff, leng + 1);
		i++;
	}
	if (info->mall_map[1] != info->row)
	{
		info->error = ERROR;
		return ;
	}
	if (ft_column(info) == ERROR)
		return ;
	if (info->error != ERROR)
		stdin_board(info);
}

void	stdin_board(t_info *info)
{
	int i;
	int j;

	j = 0;
	i = 0;
	info->board = (int **)malloc(sizeof(int *) * info->row);
	info->mall_board[0] = 1;
	while (i < info->row)
	{
		info->board[i] = (int *)malloc(sizeof(int) * info->col);
		while (j < info->col)
			info->board[i][j++] = 0;
		info->mall_board[1]++;
		i++;
		j = 0;
	}
}
