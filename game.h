#ifndef __GAME_H
# define __GAME_H

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>


typedef struct s_game_data
{
    int game_running;
    int nb_of_cell;
    int key;
    int cell_height;
    int cell_width;
    int board_height;
    int board_width;
    int margin;
    int start_y;
    int start_x;
} t_game_data;


void    draw_board(t_game_data *g_data);
void    calculate_dimensions(t_game_data *g_data);
void    key_hook(t_game_data *g_data);
int     ncurses_print_nbr(int nb, int x, int y);
int     count_len_number(int nb);
int     get_center_offset(int container_size, int item_size);

#endif