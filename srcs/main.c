/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:05 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 16:04:51 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	info_init(t_info *info)
{
	info->error = 0;
	info->condition = 0;
	info->mall_map[0] = 0;
	info->mall_map[1] = 0;
	info->mall_board[0] = 0;
	info->mall_board[1] = 0;
}

int	main(int argc, char **argv)
{
	int 	index;
	int 	fd;
	t_info   info;

	index = 1;
	if (argc == 1)
	{
		info_init(&info);
		manual_w1(&info);
		if(info.error == 1)
			write(1, "map error\n", 10);
		else
		{
			fill_board(&info);
			prt_map(&info);
		}
		free_info(&info);
	}
	else
		while (index < argc)
		{
			info_init(&info);
			fd = open(argv[index], O_RDONLY);
			if (fd == -1)
			{
				write(1, "map error\n", 10);
				break ;
			}
			set_map(fd, &info);
			close(fd);
			if (info.error == 1)
				write(1, "map error\n", 10);
			else
			{
				fill_board(&info);
				prt_map(&info);
			}
			info.error = 0;
			free_info(&info);
			index++;
		}
	return (0);
}
