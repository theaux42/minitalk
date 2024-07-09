CLIENT_SRC = ./client_src/client.c
SERVER_SRC = ./server_src/server.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_NAME = client
SERVER_NAME = server


LIBFT_PATH = ./libft
PRINTF_PATH = ./ft_printf

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#  -L $(PRINTF_PATH) -lftprintf

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	@cd $(LIBFT_PATH) && make -s
	@$(CC) $(CLIENT_OBJ) $(CFLAGS) -L $(LIBFT_PATH) -lft -o $(CLIENT_NAME)
	@printf "\033[KClient compiled successfully!\n"

$(SERVER_NAME): $(SERVER_OBJ)
	@cd $(LIBFT_PATH) && make -s
	@$(CC) $(SERVER_OBJ) $(CFLAGS) -L $(LIBFT_PATH) -lft -o $(SERVER_NAME)
	@printf "\033[KServer compiled successfully!\n"
	
clean:
	@printf "Deleting object files...\r"
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)
	@printf "\033[K✅ Object files deleted successfully!\n"

fclean: clean
	@printf "Deleting binaries...\r" > /dev/null
	@$(RM) $(CLIENT_NAME) $(SERVER_NAME)
	@@cd $(LIBFT_PATH) && make fclean -s
	@printf "\033[K✅ Binaries deleted successfully!\n"

re: fclean all

.PHONY: all clean client server fclean re