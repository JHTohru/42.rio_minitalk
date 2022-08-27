CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := libft.a
SRC_DIR := src
SRC_FILES := ft_atoi.c ft_isdigit.c ft_isspace.c ft_putchar.c ft_puterror.c \
	ft_putnbr.c ft_putnbrln.c ft_putnstr.c ft_putstr.c ft_strlen.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ_DIR := obj
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -I . -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
