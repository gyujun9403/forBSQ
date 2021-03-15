/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson </var/mail/mson>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:44:29 by mson              #+#    #+#             */
/*   Updated: 2021/03/15 23:40:55 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char buff[1024];

typedef struct	s_map
{
	int	row;
	int col;
	char	*condition;
	char	**map;
	int		**board;
}	t_map;

void	init_buff(char *buff)
{
	int index;

	index = 0;
	while (buff[index])
	{
		buff[index] = 0;
		index++;
	}
}

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index]) 
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

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
		buff[size] = c;
		size++;
		if (c == '\n')
		{	
			map[line] = (char *)malloc(sizeof(char) * size + 1);
			ft_strcpy(map[line], buff);
			map[line][size] = '\0';
			init_buff(buff);
			line++;
			size = 0;
		}
	}
	return (map);
}

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
		number += (condition[index] - '0');
		index++;
	}
	return (number);
}

char	*ft_condition(int fd, int *row)
{
	int index;
	char c;
	char	*condition;
	int size;


	index = 0;
	size = 0;
	while (read(fd, &c, 1) && c != '\n')
	{
		buff[size] = c;
		size++;
	}
	condition =(char *)malloc(sizeof(char) * size + 1);
	buff[size] = '\0';
	ft_strcpy(condition, buff);
	init_buff(buff);
	*row = split_number(condition, size);
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

t_map	set_map(int fd, t_map l_map)
{
	int row;
	char **map;
	int	**space;
	int index;

	row = 0;
	index = -1;
	l_map.condition = ft_condition(fd, &row);
	l_map.map = ft_malloc(fd, map, row);
	l_map.col = ft_column(l_map.map);
	l_map.row = row;
	space = (int **)malloc(sizeof(int *) * l_map.row);
	while (++index < row)
		space[index] =(int *)malloc(sizeof(int) * l_map.col);
	l_map.board = space;
	return (l_map);
}

int	main(int argc, char **argv)
{
	int 	index;
	int 	fd;
	t_map l_map;

	index = 1;
	if (argc == 1)
		return (0);
	else if (argc >= 2)
	{
		while (index < argc)
		{
			fd = open(argv[index], O_RDONLY);
			index++;
		}
	}
}
