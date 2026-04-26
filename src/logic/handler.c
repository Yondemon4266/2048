

#include "../game.h"


void    handle_too_small_screen()
{
    int	centered_x = get_center_offset(COLS, 18);
    int	centered_y = get_center_offset(LINES, 1);
    mvprintw(centered_y, centered_x, "Terminal too small");
}

void    handle_playing_state(t_game_data *g_data)
{
    draw_board(g_data);
}

void  handle_gameover_state(t_game_data *g_data)
{
    draw_board(g_data);
    int	centered_x = get_center_offset(COLS, 42);
    int	centered_y = get_center_offset(LINES, 1);
    mvprintw(centered_y, centered_x, "Game over ! Press 'q' or 'escape' to quit");
}

void  handle_win_state(t_game_data *g_data)
{
    draw_board(g_data);

    int	centered_x = get_center_offset(COLS, 36);
    int	centered_y = get_center_offset(LINES, 1);
    mvprintw(centered_y, centered_x, "You won ! Press 'p' to keep playing");
}
