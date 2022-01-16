/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 04:53:25 by euyi              #+#    #+#             */
/*   Updated: 2021/12/24 08:43:35 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*st[2];
	int			i[4];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i[3] = check_for_n(&st[0], &st[1], &i[2]);
	if (!st[1] || (st[1] && i[3] == 0 && !eu_free(&st[1])))
		eu_malloc(&st[0], &st[1], &i[2]);
	while (i[2] == 1)
	{
		i[0] = read(fd, &st[0][i[3]], 1);
		st[0][i[3] + 1] = 0;
		if (i[0] > 0 && st[0][i[3]] == 10)
			i[1] = 1;
		i[3]++;
		if ((i[0] == -1 || (i[0] == 0 && i[3] == 1)) && !eu_free(&st[1]))
			return (NULL);
		if (i[0] == 0 || (i[3] >= BUFFER_SIZE && i[1] == 1))
			break ;
	}
	i[3] = count_n(st[0]);
	st[0] += i[3];
	eu_memcpy(st[0] - (i[3] + 1), st[0] - i[3], i[3]);
	return (st[0] - (i[3] + 1));
}
