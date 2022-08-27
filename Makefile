CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_DIR := libft
LIBFT_LIB := libft.a
LIBFT := $(LIBFT_DIR)/$(LIBFT_LIB)

SRC_DIR := src
OBJ_DIR := obj

CLIENT := client
CLIENT_SRC_FILES := client.c
CLIENT_SRCS := $(addprefix $(SRC_DIR)/,$(CLIENT_SRC_FILES))
CLIENT_OBJS := $(CLIENT_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SERVER := server
SERVER_SRC_FILES := server.c
SERVER_SRCS := $(addprefix $(SRC_DIR)/,$(SERVER_SRC_FILES))
SERVER_OBJS := $(SERVER_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CLIENT_BONUS := client_bonus
CLIENT_BONUS_SRC_FILES := client_bonus.c
CLIENT_BONUS_SRCS := $(addprefix $(SRC_DIR)/,$(CLIENT_BONUS_SRC_FILES))
CLIENT_BONUS_OBJS := $(CLIENT_BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SERVER_BONUS := server_bonus
SERVER_BONUS_SRC_FILES := server_bonus.c
SERVER_BONUS_SRCS := $(addprefix $(SRC_DIR)/,$(SERVER_BONUS_SRC_FILES))
SERVER_BONUS_OBJS := $(SERVER_BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -o $@ $^

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c -o $@ $<

$(LIBFT):
	@make all -C $(LIBFT_DIR)

clean:
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -o $(CLIENT) $^

$(SERVER_BONUS): $(SERVER_BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -o $(SERVER) $^

.PHONY: $(CLIENT_BONUS), $(SERVER_BONUS), all, clean, fclean, re, bonus
