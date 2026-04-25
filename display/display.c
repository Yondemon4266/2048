/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:26:29 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 12:28:58 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"


static void    draw_board_lines(t_game_data *g_data)
{
    int y = -1;
    int x;
    while (++y <= g_data->nb_of_cell)
    {
        x = 0;
        while (x < g_data->board_width)
        {
            mvprintw(y * g_data->cell_height, x, "-");
            x++;
        }
    }
}

static void    draw_board_cols(t_game_data *g_data)
{
    int y;
    int x = -1;
    while (++x <= g_data->nb_of_cell)
    {
        y = 1;
        while (y <= g_data->board_height)
        {
            mvprintw(y, x * g_data->cell_width, "|");
            y++;
        }
    }
}

void    draw_board(t_game_data *g_data)
{
    draw_board_lines(g_data);
    draw_board_cols(g_data);
}
