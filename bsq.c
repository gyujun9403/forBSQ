/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson </var/mail/mson>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:44:29 by mson              #+#    #+#             */
/*   Updated: 2021/03/16 17:39:53 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

extern char g_buff[BUFF_SIZE];

char	**ft_malloc(int fd, char **map, int row)
{
	int line;
	int size;
	char c;

	line = 0;
	size = 0;
	map =(char **)malloc(sizeof(char *) * row);
	while (read(fd, &c, 1))
	{
		g_buff[size] = c;
		size++;
		if (c == '\n')
		{
			map[line] = (char *)malloc(sizeof(char) * size + 1);
			ft_strcpy(map[line], g_buff);
			map[line][size] = '\0';
			init_buff(g_buff);
			line++;
			size = 0;
		}
	}
	return (map);
}

char	*ft_condition(int fd, int *row)
{
	int index;
	char c;
	char	*first_line;
	int size;
	char	*condition;

	index = 0;
	size = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		g_buff[size] = c;
		size++;
	}
	first_line =(char *)malloc(sizeof(char) * size + 1);
	condition = (char *)malloc(sizeof(char) * 4);
	g_buff[size] = '\0';
	ft_strcpy(first_line, g_buff);
	*row = split_number(first_line, size);
	init_buff(g_buff);
	ft_strlcat(condition, first_line + size - 3, 4);
	return (condition);
}

int		ft_column(char **map)
{
	int line;
	int size;
	int check;

	line = 0;
	size = 0;
	check = 0;
	while (map[line])
	{
		while (map[line][size])
			size++;
		if (check == 0)
			check = size;
		else if (check != size)
			return (0);
		size = 0;
		line++;
	}
	return (check);
}

void	set_map(int fd, t_info *info)
{
	int row;
	char **map;
	int index;

	row = 0;
	index = -1;
	info->condition = ft_condition(fd, &row);
	info->map = ft_malloc(fd, map, row);
	info->col = ft_column(info->map);
	info->row = row;
	info->board = (int **)malloc(sizeof(int *) * info->row);
	while (++index < row)
		info->board[index] =(int *)malloc(sizeof(int) * info->col);
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
