/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:07:54 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/16 00:26:50 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

/*
**rcm[0]  rcm[1]
**rcm[2]  (i, j)
**check (i-1, j-1), (i-1, j), (i, j-1), and return minimum of it.
*/
int min_2by2(t_map *info, int i, int j)
{
	int num;
	int min;
	int rcm[3]; 
	
	rcm[0] = 0;
	rcm[1] = 0;
	rcm[2] = 0;
	if(i == 0 && j == 0)
		;
	else if (i == 0)
		rcm[1] = info->board[i][j - 1];
	else if (j == 0)
		rcm[2] = info->board[i - 1][j];
	else
	{
		rcm[0] = info->board[i - 1][j - 1];
		rcm[1] = info->board[i][j - 1];
		rcm[2] = info->board[i - 1][j];
	}
	min = rcm[0];
	min = (min < rcm[1]) ? (min) : (rcm[1]);
	min = (min < rcm[2]) ? (min) : (rcm[2]);
	return (min);
}

void prt_map(t_map *info)
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

void chage_map(t_map *info, int i_end, int j_end, int leng)
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

/*
** max[0] : side length of largest square
** max[1] : max[0]'s i index
** max[2] : max[0]'s j index
*/

void fill_board(t_map *info)
{
	int i;
	int j;
	int max[3];
	
	max[0] = 0;
	while (i < info->row)
	{
		while (j < info->col)
		{
			if (info->map[i][j] == info->condition[0])
				info->board[i][j] = min_2by2(info, i, j) + 1;
			else
				info->board[i][j] = 0;
			if (max[0] < info->board[i][j])
			{
				max[0] = info->board[i][j];
				max[1] = i;
				max[2] = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	chage_map(info, max[1], max[2], max[0]);
}

int main()
{
	int i = 0;
	int j = 0;
	char tmap[9][28] =	{"...........................", 
				 "....o......................", 
				 "............o..............", 
				 "...........................", 
				 "....o......................", 
				 "...............o...........", 
				 "...........................", 
				 "......o..............o.....", 
				 "..o.......o................"};
	int tboard[9][28]; 
	t_map info;

	info.row = 9;
	info.col = 28;

	info.condition = (char *)malloc(4);
	info.condition = ".ox";
	info.map = (char **)malloc(sizeof(char *) * info.row);
	info.board = (int **)malloc(sizeof(int *) * info.row);
	while (i < info.row)
	{
		info.map[i] = (char *)malloc(sizeof(char) * info.col);
		info.map[i] = tmap[i];
		info.board[i++] = (int *)malloc(sizeof(int) * info.col);
	}
	fill_board(&info);
	prt_map(&info);
}
