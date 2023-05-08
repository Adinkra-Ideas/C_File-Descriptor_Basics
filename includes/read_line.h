#ifndef __READ_LINE__H
# define __READ_LINE__H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (20)
# endif

# define MAX_FILE_SIZE 100000001
# define MAX_LINE_LEN 50000001

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int 	check_for_n(char *ptr);
char 	*copy_one_line(char *dest, char **index);
void	shift_index(char **src, int *nptr);
char    *get_next_line(int fd);
void 	exit_with_error( const char *msg );

#endif
