#include "../includes/read_line.h"

char    *read_line( int fd ){
	static char	*buffer, *buffer_tmp;
	char		*line;
	int 		count = 0, i = 0, j = 0;

	if ( fd < 0 )
		return (NULL);

	if ( ! buffer && ((buffer = (char *) malloc(MAX_FILE_SIZE)), 1))
		buffer_tmp = buffer;
	else if ( buffer && buffer[0] && !check_for_n(buffer))
		shift_index(&buffer, &count);

	while ( ! check_for_n(buffer) ){
		i = read(fd, buffer + j, BUFFER_SIZE);
		if (i > 0 && ((j += i), 1))
			buffer[j] = 0;
		if (i <= 0 && (!buffer || (buffer && !buffer[0])) && count == 0 && (free(buffer_tmp), 1))
			return (NULL);
		if (i <= 0)
			break ;
	}

	if (count != 0)
		buffer -= count;

	line = (char *) malloc(MAX_LINE_LEN);
	copy_one_line(line, &buffer);
	return (line);
}

char	*copy_one_line(char *dest, char **index){
	int i = 0;

	while (index && index[0] && index[0][0]){
		dest[i] = index[0][0];
		i++;
		if (index[0][0] == '\n' && ++index[0])
			break ;
		index[0]++;		
	}
	dest[i] = 0;
	return (dest);
}

int 	check_for_n(char *ptr){
	if (!ptr)
		return (0);
	while (*ptr){
		if (*ptr == '\n')
			return (1);
		ptr++;
	}
	return (0);
}

void	shift_index(char **src, int *nptr){
	while (src && src[0] && src[0][0]){
		(*src)++;
		*nptr += 1;
	}
}

void exit_with_error( const char *error_msg ) {
	if ( error_msg )
		write(2, error_msg, strlen(error_msg));
	exit(1);
}

int main ( int argc, char *argv[] ) {
	char 	*line;
	int		fd;

	if ( argc <= 1 )
		exit_with_error("Wrong number of arguments\nUsage ./read_line [filepath]\n");
	
	if ( (fd = open(argv[1], O_RDONLY)) == -1 )
		exit_with_error("Unable to read from filepath specified\n");
	
	while( (line = read_line(fd)) ) {
		write(1, line, strlen(line));
		free(line);
	}

	close(fd);

	return 0;
}
