
#include "../game.h"

void    draw_menu_borders(t_game_data *g_data)
{
    int y = 0;
    int x = 0;
    while (y < 2)
    {
        x = 0;
        while (x < g_data->board_width)
        {
            mvaddch(g_data->start_y + (y * g_data->board_height), g_data->start_x + x, '-');
            x++;
        }
        y++;
    }
    x = 0;
    y = 0;
    while (x < 2)
    {
        y = 0;
        while (y < g_data->board_height)
        {
            mvaddch(g_data->start_y+ y, g_data->start_x + (x * g_data->board_width), '|');
            y++;
        }
        x++;
    }
}



void    draw_menu_elements(t_game_data *g_data)
{
    int i = 0;
    char    *menu_elements_beginning[3] = {"Start playing", "ASCII ART","Quit game"};
    char    *menu_elements_started[4] = {"Continue", "Start new game", "ASCII ART", "Quit game"};

    char    **menu_elements = NULL;

    if (g_data->started)
        menu_elements = menu_elements_started;
    else
        menu_elements = menu_elements_beginning;
    
    while (i < g_data->menu_data.element_count)
    {
        int text_len = ft_strlen(menu_elements[i]);
        int centered_x = g_data->start_x + get_center_offset(g_data->board_width, text_len);
        int first_line = g_data->menu_data.start_elements_y - 1 + (i * 2);
        int x = 1;
        while (x <= g_data->board_width - 1)
        {
            mvaddch(first_line, g_data->start_x + x, '-');
            x++;
        }
        
        if (g_data->menu_data.selection == i)
        {
            attron(COLOR_PAIR(2));
            mvprintw(g_data->menu_data.start_elements_y + (i * 2), centered_x, "%s", menu_elements[i]);
            if (g_data->is_ascii && g_data->started && i == 2)
                printw("%s", " OK");
            else if (g_data->is_ascii && !g_data->started && i == 1)
                printw("%s", " OK");
            attroff(COLOR_PAIR(2));
        }
        else
        {
            mvprintw(g_data->menu_data.start_elements_y + (i * 2), centered_x, "%s", menu_elements[i]);
            if (g_data->is_ascii && g_data->started && i == 2)
                printw("%s", " OK");
            else if (g_data->is_ascii && !g_data->started && i == 1)
                printw("%s", " OK");
        }
        
        x = 1;
        int separator_y = g_data->menu_data.start_elements_y + (i * 2) + 1; 

        while (x <= g_data->board_width - 1) 
        {
            mvaddch(separator_y, g_data->start_x + x, '-');
            x++;
        }
        i++;
    }
}