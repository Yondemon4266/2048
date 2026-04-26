
NAME = 2048

CC = cc

SIZE ?= 4

CFLAGS = -Wall -Wextra -Werror -MMD -MP -DBOARD_SIZE=$(SIZE)

NCURSES_LIB = -lncurses

SRC = src

DISPLAY=display

BUILD_DIR = .build

C_FILES = src/main.c \
          src/hooks.c \
          src/utils.c \
          src/display/display_board.c \
          src/display/display_utils.c \
          src/display/display_menu.c \
          src/display/display_digit_ascii.c \
          src/logic/add_number.c \
          src/logic/check_game_finished.c \
          src/logic/check_win_cond_value.c \
          src/logic/count_zeros.c \
          src/logic/handler.c \
          src/logic/reset_merged.c \
          src/logic/swipe.c \
          src/logic/reset_grid.c

O_FILES = $(C_FILES:%.c=$(BUILD_DIR)/%.o)

INCLUDES = game.h

DEPS = $(O_FILES:.o=.d)

$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -g -o $(NAME) $(NCURSES_LIB)

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