
NAME = 2048

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -MP

NCURSES_LIB = -lncurses

BUILD_DIR = .build

C_FILES = main.c display/display_utils.c display/display.c display/hooks.c

O_FILES = $(C_FILES:%.c=$(BUILD_DIR)/%.o)

INCLUDES = game.h

DEPS = $(O_FILES:.o=.d)

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME) $(NCURSES_LIB)

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)
fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re