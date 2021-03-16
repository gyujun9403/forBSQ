#include "bsq.h"

void	map_cond_check(char c, t_info *info)
{
	if (c != info->condition[0] && c != info->condition[1])
			info->error = 1;
}

void	row_check(int fd, t_info *info)
{
	char c;
	if (read(fd,&c,1))
		info->error = 1;
}
