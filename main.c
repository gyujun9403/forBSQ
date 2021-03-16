/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:05 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/16 20:17:08 by gyeon            ###   ########.fr       */
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
			set_map(fd, &info);
			close(fd);
			fill_board(&info);
			while (i < info.row)
			{
				while (j < info.col)
					printf("%d ", info.board[i][j++]);
				printf("\n");
				i++;
				j = 0;
			}
			prt_map(&info);
			index++;
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
