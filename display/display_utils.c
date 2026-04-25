
#include "../game.h"


void    calculate_dimensions(t_game_data *g_data)
{
    g_data->cell_height = LINES / g_data->nb_of_cell - (g_data->margin * 2);
    g_data->cell_width = COLS / g_data->nb_of_cell - (g_data->margin * 2);
    g_data->board_height = g_data->cell_height * g_data->nb_of_cell;
    g_data->board_width = g_data->cell_width * g_data->nb_of_cell;
}