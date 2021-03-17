/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:17:40 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 15:20:24 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_cond_check(char c, t_info *info)
{
	if ((c != info->condition[0] && c != info->condition[1])
			&& (c >= ' ' && c <= '~'))
	{
//		printf("11111\n");
			info->error = 1;
	}
}

void	row_check(int fd, t_info *info, int line)
{
	char c;
	if (read(fd,&c,1) && info->row != line - 1)
	{
//		printf("222222\n");
		info->error = 1;
	}
}

void chk_condition(t_info *info, char *buff, int size)
{
	int i;

	i = 0;
	if (size < 4)
	{
//		printf("333333333");
		info->error = 1;
		return ;
	}
	while (i < size - 3)
	{
		if (!(buff[i] >= '0' && buff[i] <= '9') && buff[0] == '0')
		{
//			printf("size : %d / i :% d / buff :  %c", size, i, buff[i]);
			info->error = 1;
		}
		i++;
	}
	if (buff[size - 3] == buff[size - 1])
	{
//		printf("5555555555555");
		info->error = 1;
	}
	if (buff[size - 3] == buff[size - 2])
	{
//		printf("6666666666666666");
		info->error = 1;
	}
	if (buff[size - 2] == buff[size - 1])
	{
//		printf("77777777777777");
		info->error = 1;
	}

	return ;
}
