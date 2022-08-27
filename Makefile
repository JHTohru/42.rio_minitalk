CC := cc
CFLAGS := -Wall -Wextra -Werror
CLIENT := client
CLIENT_SRCS := client.c utils.c utils2.c
CLIENT_OBJS := $(CLIENT_SRCS:%.c=%.o)
CLIENT_BONUS := client_bonus
CLIENT_BONUS_SRCS := client_bonus.c utils.c utils2.c
CLIENT_BONUS_OBJS := $(CLIENT_BONUS_SRCS:%.c=%.o)
SERVER := server
SERVER_SRCS := server.c utils2.c utils3.c
SERVER_OBJS := $(SERVER_SRCS:%.c=%.o)
SERVER_BONUS := server_bonus
SERVER_BONUS_SRCS := server_bonus.c utils2.c utils3.c
SERVER_BONUS_OBJS := $(SERVER_BONUS_SRCS:%.c=%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(SERVER): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(BONUS): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $^

$(SERVER_BONUS): $(SERVER_BONUS_OBJS)
	@$(CC) $(CFLAGS) -o $(SERVER) $^

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: $(CLIENT_BONUS), $(SERVER_BONUS), all, clean, fclean, re, bonus
