#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_map
{
	int	row;
	int col;
	char	*condition;
	char	**map;
	int		**board;
}	t_map;


void	ft_malloc(int fd, char **map, int row)
{
	int line;
	int size;
	char c;
	int check;

	check = 0;
	line = 0;
	map =(char **)malloc(sizeof(char *) * row);
	while (read(fd, &c, 1))
	{
		if (check != 0)
			size++;
		if (c == '\n')
		{	
			if (check != 0)
			{
				map[line] = (char *)malloc(sizeof(char) * size);
				line++;
				size = 0;
				check++;
			}
		}
	}
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
		number += condition[index] - '0';
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
		size++;
	condition =(char *)malloc(sizeof(char) * size + 1);
	while (read(fd, &c, 1) && c != '\n')
	{
		condition[index] = c;
		index++;
	}
	condition[index] = '\0';
	*row = split_number(condition, size);
	return (condition);
}

int		ft_column(int fd)
{
	int index;
	int size;
	int check;
	char c;

	index = 0;
	size = 0;
	check = 0;
	while (read(fd, &c, 1))
	{
		if (!check)
			size++;
		if (c == '\n')
			check++;
		if (check && c == '\n')
			return (size);
	}
	return (0);
}

char	**store(int fd, int row)
{
	int 	index;
	int		line;
	char 	c;
	char	**map;

	index = 0;
	line = 0;
	ft_malloc(fd, map, row);
	while (read(fd , &c, 1))
	{	
		if (c == '\n')
		{
			line++;
			index = 0;
		}
		if (line > 0)
		{	
			map[line - 1][index] = c;
			index++;
		}
	return (map);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int index;
	int row;
	int		**space;
	int		j;
	int 	fd;
	int		i;
	int 	k;

	k = 0;
	i = 0;
	t_map l_map;
	index = 1;
	row = 0;
	j = -1;
	if (argc == 1)
		write(1,"c",1);
	else if (argc >= 2)
	{
		while (index < argc)
		{
			fd = open(argv[index], O_RDONLY);
			l_map.col = ft_column(fd);
			l_map.condition = ft_condition(fd, &row);
			l_map.map =  store(fd, row);
			l_map.row = row;
			space =(int **)malloc(sizeof(int *) * l_map.row);
			while (++j < row)
				space[j] =(int *)malloc(sizeof(int) * l_map.col);
			l_map.board = space;
			index++;
		}
		printf("%d",l_map.row);
		while (i < l_map.row)
		{
			while(k < l_map.col)
			{
				printf("%c",l_map.map[i][k]);
				k++;
			}
			i++;
			k = 0;
		}
	}
}
