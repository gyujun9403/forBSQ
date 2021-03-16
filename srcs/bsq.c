/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson </var/mail/mson>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:44:29 by mson              #+#    #+#             */
/*   Updated: 2021/03/17 03:44:06 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern char g_buff[BUFF_SIZE];

void	ft_malloc(int fd, t_info *info)
{
	int line;
	int size;
	char c;

	line = 0;
	size = 0;
	info->map =(char **)malloc(sizeof(char *) * info->row);
	while (read(fd, &c, 1))
	{
		if (line ==  info->row)
		{
			info->error = 1;
			break;
		}
		if (c == '\n' && line < info->row)
		{
			info->map[line] = (char *)malloc(sizeof(char) * size + 1);
			ft_strcpy(info->map[line], g_buff);
			info->map[line][size] = '\0';
			init_buff(g_buff);
			line++;
			size = 0;
		}
		else
		{
			g_buff[size++] = c;
			map_cond_check(c,info);
		}
	}
	//row_check(fd, info, line);
}

void	ft_condition(int fd, t_info *info)
{
	int index;
	char c;
	int size;
	int leng;

	index = 0;
	size = 0;
	while ((leng = read(fd, &c, 1)) && c != '\n')
	{
		g_buff[size] = c;
		size++;
	}
	chk_condition(info, g_buff, size);
	info->row = split_number(g_buff, size);
	info->condition = (char *)malloc(sizeof(char) * 4);
	ft_strlcat(info->condition, g_buff + size - 3, 4);
}

int		ft_column(t_info *info)
{
	int line;
	int size;
	int check;

	line = 0;
	size = 0;
	check = 0;
	while (line < info->row)
	{
		while (info->map[line][size])
			size++;
		if (check == 0)
			check = size;
		else if (check != size)
		{
			info->error = 1;
			return (0);
		}
		size = 0;
		line++;
	}
	return (check);
}

void	set_map(int fd, t_info *info)
{
	int index;
	int j;
	index = -1;
	ft_condition(fd, info);
	ft_malloc(fd, info);
	info->col = ft_column(info);
	info->board = (int **)malloc(sizeof(int *) * info->row);
	while (++index < info->row)
	{
		info->board[index] =(int *)malloc(sizeof(int) * info->col);
		j = 0;
		while (j < info->col)
			info->board[index][j++] = 0;
	}
}

void	free_info(t_info *info)
{
	int i;

	i = 0;
	free(info->condition);
	while (i < info->row)
	{
		free(info->map[i]);
		free(info->board[i]);
		i++;
	}
	free(info->map);
	free(info->board);
}
