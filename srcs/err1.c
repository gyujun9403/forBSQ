/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:17:40 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 01:22:08 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	error_isprintable(*t_info info, char c)
{
	if(c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}

void chk_condition(*t_info info, char *buff, int size)
{
	int i;

	i = 0;
	if (size < 4)
	{
		info->error = 1;
		return ;
	}
	while (i < size - 3)
	{
		if (!(buff[i] >= '0' && buff[i] <= 9))
			info->error = 1;
		i++;
	}
	if (buff[size - 3] == buff[size - 1])
		info->error = 1;
	if (buff[size - 3] == buff[size - 2])
		info->error = 1;
	if (buff[size - 2] == buff[size - 1])
		info->error = 1;
	return ;
}
