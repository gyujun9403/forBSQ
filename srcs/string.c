/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeon <gyeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 00:14:30 by gyeon             #+#    #+#             */
/*   Updated: 2021/03/16 16:51:56 by gyeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_buff(char *g_buff)
{
	int index;

	index = 0;
	while (g_buff[index])
	{
		g_buff[index] = 0;
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
