NAME = read_line

SRCS = read_line.c

OBJDIR = build/
SRCDIR = srcs/
HEADER = includes/

OBJS := $(SRCS:.c=.o)
SRCS_PREFIXED := $(addprefix $(SRCDIR), $(SRCS))
OBJECTS_PREFIXED := $(addprefix $(OBJDIR), $(OBJS))

CC = cc

CFLAGS = -Wall	-Werror	-Wextra -pedantic -g3 -fsanitize=address -D BUFFER_SIZE=1200

all: $(NAME)

$(NAME): $(OBJECTS_PREFIXED) $(OBJDIR)
	$(CC) $(CFLAGS) $(OBJECTS_PREFIXED) -o $(NAME)

$(OBJECTS_PREFIXED): $(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -I$(HEADER) $< -o $@ 

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all	clean	fclean	re
