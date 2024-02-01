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

all: $(CLIENT_NAME) $(SERVER_NAME)
	$(CC) $(CLIENT_OBJ) $(CFLAGS) -L $(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf -o $(CLIENT_NAME) 
	$(CC) $(SERVER_OBJ) $(CFLAGS) -L $(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(CFLAGS) -L $(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) $(CFLAGS) -L $(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf -o $(SERVER_NAME)

clean:
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean client server fclean re