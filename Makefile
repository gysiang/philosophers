# Compiler and Flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I./includes

# Directories

INCLUDES		= ./includes
SRC_DIR			= src/philo

SRC_FILES		= $(addprefix $(SRC_DIR)/, \
					init.c \
					monitor.c \
					routine.c \
					threads.c \
					time.c \
					utils.c \
					main.c)

OBJECTS			= $(SRC_FILES:.c=.o)

NAME			= philo

#Targets

all:		$(NAME)

$(NAME):	$(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
