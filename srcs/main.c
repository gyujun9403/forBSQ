/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:05 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 03:50:08 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int 	index;
	int 	fd;
	t_info   info;

	index = 1;
	info.error = 0;
	if (argc == 1)
	{
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
			fd = open(argv[index], O_RDONLY);
			set_map(fd, &info);
			close(fd);
			if(info.error == 1)
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
