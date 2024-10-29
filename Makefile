SRC_1 = src/client.c
OBJ_1 = $(SRC_1:.c=.o)

SRC_2 = src/server.c
OBJ_2 = $(SRC_2:.c=.o)

SRC_3 = src/server_bonus.c
OBJ_3 = $(SRC_3:.c=.o)

SRC_4 = src/client_bonus.c
OBJ_4 = $(SRC_4:.c=.o)

CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -L./ft_printf 

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \e[0;93m

./ft_printf/ft_printf.a: FORCE
	@$(MAKE) -C ./ft_printf

$(NAME_CLIENT): $(OBJ_1) ./ft_printf/ft_printf.a
	$(CC) $(OBJ_1) $(CFLAGS) $(LDFLAGS) -o $(NAME_CLIENT)
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)    CLIENT $(GREEN)[OK]$(NC)    |\n\
					+---------------------+"

$(NAME_SERVER): $(OBJ_2) ./ft_printf/ft_printf.a
	$(CC) $(CFLAGS) $(OBJ_2) $(LDFLAGS) ./ft_printf/ft_printf.a -o $(NAME_SERVER)
	@echo "	 			+---------------------+\n\
					|  $(YELLOW)   SERVER $(GREEN)[OK]$(NC)     |\n\
					+---------------------+"
$(NAME_SERVER_BONUS): $(OBJ_3) ./ft_printf/ft_printf.a
		$(CC) $(OBJ_3) $(CFLAGS) $(LDFLAGS) ./ft_printf/ft_printf.a -o $(NAME_SERVER_BONUS)
		@echo "	 			+---------------------+\n\
					|  $(YELLOW)BONUS SERVER $(GREEN)[OK]$(NC)  |\n\
					+---------------------+"
$(NAME_CLIENT_BONUS): $(OBJ_4) ./ft_printf/ft_printf.a
		$(CC) $(OBJ_4) $(CFLAGS) $(LDFLAGS) ./ft_printf/ft_printf.a -o $(NAME_CLIENT_BONUS)
		@echo "	 			+---------------------+\n\
					|  $(YELLOW)BONUS CLIENT $(GREEN)[OK]$(NC)  |\n\
					+---------------------+"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

m: $(NAME_CLIENT) $(NAME_SERVER)

b: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
	rm -f $(OBJ_1) $(OBJ_2) $(OBJ_3) $(OBJ_4)

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	$(MAKE) -C ./ft_printf fclean

re: fclean all

.PHONY: all clean fclean re FORCE
