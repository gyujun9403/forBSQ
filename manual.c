#include "bsq.h"
#include <stdio.h>

extern char g_buff[BUFF_SIZE];

void manual_w1(t_info *info)
{
	int readin;
	int leng;
	int i;
	char w;

	leng = 0;
	while ((readin = read(0, &w, 1)) > 0 && w != '\n')
	{
		g_buff[leng++] = w;
	}
	info->row = split_number(g_buff, leng);
	info->condition = (char *)malloc(4);
	ft_strlcat(info->condition, g_buff + leng - 3, 4);
	manual_w2(info);
}

void manual_w2(t_info *info)
{
	int i;
	int leng;
	int readin;
	char w;

	i = 0;
	info->map = (char **)malloc(sizeof(char *) * info->row);
	while (i < info->row)
	{
		leng = 0;
		while ((readin = read(0, &w, 1)) > 0 && w != '\n')
		{
			g_buff[leng++] = w;
		}
		info->map[i] = (char *)malloc(sizeof(char) * leng + 1);
		ft_strlcat(info->map[i], g_buff, leng + 1);
		i++;
	}
	info->col = ft_column(info->map);
	info->board = (int **)malloc(sizeof(int *) * info->row);
	i = 0;
	while (i < info->row)
		info->board[i++] = (int *)malloc(sizeof(int) * info->col);
}
