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
} t_game_data;


void    draw_board(t_game_data *g_data);
void    calculate_dimensions(t_game_data *g_data);
void    key_hook(t_game_data *g_data);

#endif