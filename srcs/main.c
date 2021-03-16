/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:52:05 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/17 00:49:07 by gyeon            ###   ########.fr       */
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
			prt_map(&info);
			index++;
			free_info(&info);
		}
	return (0);
}
