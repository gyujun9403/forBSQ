/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:14:51 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/16 00:27:50 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 1024

typedef struct s_map
{
	int row;
	int col;
	char *condition;
	char **map;
	int **board;
}	t_map;

char g_buff[BUFF_SIZE];

//int	split_number(char *condition, int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

#endif
