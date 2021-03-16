/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:05 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/16 18:51:08 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int 	index;
	int 	fd;
	t_info   info;
	int i = 0;
	int j = 0;

	index = 1;
	if (argc == 1)
	{
		manual_w1(&info);
		fill_board(&info);
		prt_map(&info);
		free_info(&info);
	}
	else
		while (index < argc)
		{
			fd = open(argv[index], O_RDONLY);
			printf("open\n");
			printf("%d\n", fd);
			set_map(fd, &info);
			printf("et_map\n");
			close(fd);
			printf("close\n");
			fill_board(&info);
			printf("fill_board\n");
			prt_map(&info);
			printf("ptr_map\n");
			index++;
			printf("%d\n", info.row);
			printf("%d\n", info.col);
			printf("%s\n", info.condition);
			while (i < info.row)
			{
				while (j < info.col)
					printf("%d ", info.board[i][j++]);
				printf("\n");
				i++;
				j = 0;
			}
			free_info(&info);
		}
	return (0);
}
	/*	printf("%d\n", l_map.row);
		printf("%d\n", l_map.col);
		printf("%s\n", l_map.condition);*/

		/*while (i < l_map.row)
		{
			while (j < l_map.col)
				printf("%d ", l_map.board[i][j++]);
			printf("\n");
			i++;
			j = 0;
		}*/
