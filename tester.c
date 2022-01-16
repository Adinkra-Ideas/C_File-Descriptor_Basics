/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 07:11:44 by euyi              #+#    #+#             */
/*   Updated: 2022/01/16 03:19:51 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*ptr;
	
	fd = open("deepthought.txt", O_RDONLY);
	while ((ptr = get_next_line(fd)) != 0)
		printf("%s", ptr);
	return (0);
}
