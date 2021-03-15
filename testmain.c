#include "bsq.h"
#include <stdio.h>

extern char g_buff[BUFF_SIZE];

void manual_w2(t_map *info);
int	split_number(char *condition, int size)
{
	int index;
	int number;

	index = 0;
	number = 0;
	while (index <size - 3)
	{
		if (condition[index] < '0' || condition[index] > '9')
			return (0);
		number *= 10;
		number += condition[index] - '0';
		index++;
	}
	return (number);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (*dest && i < size)
	{
		++i;
		++dest;
	}
	while (*src && i + 1 < size)
	{
		*dest = *src;
		++dest;
		++src;
		++i;
	}
	if (i < size)
		*dest = 0;
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}

void manual_w1(t_map *info)
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

void manual_w2(t_map *info)
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
}

int main(int ac, char **av)
{
	t_map info;	
	if (ac == 1)
	{
		manual_w1(&info);
		printf("%s\n", info.condition);
		printf("%d\n", info.row);
		printf("%s\n", info.map[0]);
		printf("%s\n", info.map[1]);
	}
}
