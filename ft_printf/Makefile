NAME = ft_printf.a
SOURCES = \
		 ft_printf.c ft_printf_hex.c ft_printf_num.c 

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?
	@echo "				+---------------------+\n\
					|  $(YELLOW)   PRINTF $(GREEN)[OK]$(NC)     |\n\
					+---------------------+"

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
