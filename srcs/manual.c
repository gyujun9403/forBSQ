#include "bsq.h"

extern char g_buff[BUFF_SIZE];

void manual_w1(t_info *info)
{
	int readin;
	int leng;
	char w;

	leng = 0;
	while ((readin = read(0, &w, 1)) > 0 && w != '\n')
	{
		g_buff[leng++] = w;
	}
	chk_condition(info, g_buff, leng);
	if (info->error == ERROR)
		return ;
	info->row = split_number(g_buff, leng);
	info->condition = (char *)malloc(4);
	info->mall_condition = 1;
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
	info->mall_map[0] = 1;
	while (i < info->row)
	{
		leng = 0;
		while ((readin = read(0, &w, 1)) > 0 && w != '\n')
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
	info->col = ft_column(info);
	info->board = (int **)malloc(sizeof(int *) * info->row);
	info->mall_board[0] = 1;
	i = 0;
	while (i < info->row)
	{
		info->board[i++] = (int *)malloc(sizeof(int) * info->col);
		info->mall_board[1]++;
	}
}
