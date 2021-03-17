/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:07:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 19:27:26 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/*
**rcm[0]  rcm[1]
**rcm[2]  (i, j)
**check (i-1, j-1), (i-1, j), (i, j-1), and return minimum of it.
*/

int		min_2by2(t_info *info, int i, int j)
{
	int min;
	int rcm[3];

	rcm[0] = 0;
	rcm[1] = 0;
	rcm[2] = 0;
	if (i == 0 && j == 0)
		;
	else if (i != 0 && j == 0)
		rcm[1] = info->board[i - 1][j];
	else if (i == 0 && j != 0)
		rcm[2] = info->board[i][j - 1];
	else if (i != 0 && j != 0)
	{
		rcm[0] = info->board[i - 1][j - 1];
		rcm[1] = info->board[i - 1][j];
		rcm[2] = info->board[i][j - 1];
	}
	min = rcm[0];
	min = (min < rcm[1]) ? (min) : (rcm[1]);
	min = (min < rcm[2]) ? (min) : (rcm[2]);
	return (min);
}

void	prt_map(t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info->row)
	{
		while (j < info->col)
		{
			write(1, &info->map[i][j++], 1);
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

void	chage_map(t_info *info, int i_end, int j_end, int leng)
{
	int i_st;
	int j_st;

	i_st = i_end - leng + 1;
	j_st = j_end - leng + 1;
	while (i_st <= i_end)
	{
		while (j_st <= j_end)
		{
			info->map[i_st][j_st++] = info->condition[2];
		}
		j_st = j_end - leng + 1;
		i_st++;
	}
}

void	fill_man(int *max, int first, int second, int third)
{
	max[0] = first;
	max[1] = second;
	max[2] = third;
}

/*
** max[0] : side length of largest square
** max[1] : max[0]'s i index
** max[2] : max[0]'s j index
*/

void	fill_board(t_info *info)
{
	int i;
	int j;
	int max[3];

	i = 0;
	j = 0;
	fill_max(max, 0, 0, 0);
	while (i < info->row)
	{
		while (j < info->col)
		{
			if (info->map[i][j] == info->condition[0])
				info->board[i][j] = min_2by2(info, i, j) + 1;
			else
				info->board[i][j] = 0;
			if (max[0] < info->board[i][j])
				fill_max(max, info->board[i][j], i, j);
			j++;
		}
		i++;
		j = 0;
	}
	chage_map(info, max[1], max[2], max[0]);
}
