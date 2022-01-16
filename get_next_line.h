/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 04:54:09 by euyi              #+#    #+#             */
/*   Updated: 2022/01/10 19:52:12 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*eu_free(char **ptr);
char	*eu_malloc(char **ptr, char **cpy, int *flag);
void	eu_memcpy(char *dest, const char *src, size_t n);
int		count_n(char *ptr);
int		check_for_n(char **ptr, char **cpy, int *flagforloop);

#endif
