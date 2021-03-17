/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:17:40 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 22:41:36 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	chk_word(char c, t_info *info)
{
	if (!(c >= ' ' && c <= '~'))
		info->error = ERROR;
}

void	map_cond_check(char c, t_info *info)
{
	if ((c != info->condition[0] && c != info->condition[1])
			|| (!(c >= ' ' && c <= '~')))
	{
		info->error = ERROR;
	}
}

void	row_check(int fd, t_info *info, int line)
{
	char c;

	if (read(fd, &c, 1) && info->row != line - 1)
		info->error = ERROR;
}

void	chk_condition(t_info *info, char *buff, int size)
{
	int i;

	i = 0;
	if (size < 4)
	{
		info->error = ERROR;
		return ;
	}
	while (i < size - 3)
	{
		if (!(buff[i] >= '0' && buff[i] <= '9') || buff[0] == '0')
			info->error = ERROR;
		i++;
	}
	if (buff[size - 3] == buff[size - 1])
		info->error = ERROR;
	if (buff[size - 3] == buff[size - 2])
		info->error = ERROR;
	if (buff[size - 2] == buff[size - 1])
		info->error = ERROR;
	return ;
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
			return (info->error);
		}
		size = 0;
		line++;
	}
	info->col = check;
	return (info->error);
}
