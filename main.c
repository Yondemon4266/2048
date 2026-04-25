/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:47:24 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 14:59:40 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"


void    init_game_data(t_game_data *g_data)
{
    g_data->nb_of_cell = 4;
    g_data->game_running = 1;
    g_data->margin = 1;
    calculate_dimensions(g_data);
}

/*
    t_grid  grid = {4, 4, 0, {
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}},
        {{0, 0}, {0, 0}, {0, 0}, {0, 0}}
    }};
*/

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
        clear();
        draw_board(&g_data);
        refresh();
        g_data.key = getch();
        key_hook(&g_data);
    }

    endwin();
    return (0);
}