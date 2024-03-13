# Compiler and Flags
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

# Directories

INCLUDES		= ./includes
SRC_DIR			= philo

SRC_FILES		= $(addprefix $(SRC_DIR)/,
					main.c)

OBJECTS			= $(SRC_FILES:.c=.o)

NAME			= philo

#Targets

all:		$(NAME) $(INCLUDES) $(OBJECTS)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(NAME):	$(INCLUDES_DIR)

clean:
		rm - f $(OBJECTS)

fclean:
		rm - f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
