/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:47:24 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 19:16:07 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


void    init_game_data(t_game_data *g_data)
{
    g_data->nb_of_cell = 4;
    g_data->game_running = 1;
    g_data->margin = 1;
    g_data->grid.row = g_data->nb_of_cell;
    g_data->grid.column = g_data->nb_of_cell;
    add_number(&g_data->grid, get_new_pos(g_data->grid));
    add_number(&g_data->grid, get_new_pos(g_data->grid));
    calculate_dimensions(g_data);
}



int main()
{
    t_game_data g_data = {0};
    srand(time(NULL));
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);
    init_game_data(&g_data);
    while (g_data.game_running)
    {
        if (!gameover(g_data.grid))
        {
            clear();
            draw_board(&g_data);
            refresh();
            g_data.key = getch();
            reset_merged(&g_data.grid);
            if (!key_hook(&g_data))
                continue;
            add_number(&g_data.grid, get_new_pos(g_data.grid));
        }
        else
            break;
    }

    endwin();
    return (0);
}