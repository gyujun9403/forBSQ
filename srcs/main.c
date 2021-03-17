/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:28:36 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 20:44:03 by gyeon            ###   ########.fr       */
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

void	start(int index, int argc, char **argv, t_info *info)
{
	int fd;

	while (++index < argc)
	{
		info_init(info);
		if (index != 1)
			write(1, "\n", 1);
		fd = open(argv[index], O_RDONLY);
		if (fd == -1)
		{
			write(1, "map error\n", 10);
			index++;
			continue ;
		}
		set_map(fd, info);
		close(fd);
		if (info->error == 1)
			write(1, "map error\n", 10);
		else
		{
			fill_board(info);
			prt_map(info);
		}
		free_info(info);
	}
}

int		main(int argc, char **argv)
{
	int		index;
	t_info	info;

	index = 0;
	if (argc == 1)
	{
		info_init(&info);
		stdin_condition(&info);
		if (info.error == 1)
			;
		else
		{
			fill_board(&info);
			prt_map(&info);
		}
		free_info(&info);
	}
	else
		start(index, argc, argv, &info);
	return (0);
}
