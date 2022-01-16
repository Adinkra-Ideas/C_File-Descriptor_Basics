/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 04:54:09 by euyi              #+#    #+#             */
/*   Updated: 2021/12/24 07:22:54 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*eu_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (*ptr);
}

char	*eu_malloc(char **ptr, char **cpy, int *flag)
{
	*ptr = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1025));
	*cpy = *ptr;
	*flag = 1;
	*ptr[0] = 97;
	*ptr += 1;
	*ptr[0] = 98;
	return (NULL);
}

void	eu_memcpy(char *dest, const char *src, size_t n)
{
	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = 0;
}

int	count_n(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != 0 && ptr[i] != 10)
		i++;
	return (i + 1);
}

int	check_for_n(char **ptr, char **cpy, int *flagforloop)
{
	char	*tmp;
	int		i;

	i = 0;
	*flagforloop = 0;
	if (!(*cpy))
		return (0);
	while (*cpy && ptr[0][i] != 0)
	{
		if (ptr[0][i] == 10)
			return (i + 1);
		i++;
	}
	if (*cpy && i == 0 && ptr[0][i] == 0)
		return (0);
	tmp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1025));
	eu_memcpy(tmp, *ptr, i);
	eu_free(&(*cpy));
	eu_malloc(&(*ptr), &(*cpy), flagforloop);
	eu_memcpy(*ptr, tmp, i);
	free(tmp);
	return (i);
}
