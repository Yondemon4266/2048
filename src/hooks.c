/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:27:16 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 12:15:17 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void key_hook(t_game_data *g_data)
{
    int moved = 0;

    if (g_data->key == 'q' || g_data->key == 'Q' || g_data->key == 27)
    {
        g_data->current_state = STATE_QUIT;
        return ;
    }
    if (g_data->key == KEY_RESIZE)
    {
        calculate_dimensions(g_data);
        return ;
    }
    if (!is_terminal_valid(g_data))
        return ; 

    if (g_data->current_state == STATE_PLAYING)
    {
        switch (g_data->key)
        {
            case KEY_LEFT:  moved = going_left(&g_data->grid); break;
            case KEY_RIGHT: moved = going_right(&g_data->grid); break;
            case KEY_UP:    moved = going_up(&g_data->grid); break;
            case KEY_DOWN:  moved = going_down(&g_data->grid); break;
        }
        if (moved > 0)
        {
            add_number(&g_data->grid, get_new_pos(g_data->grid));
            
            reset_merged(&g_data->grid);

            if (is_win(g_data->grid) && g_data->win_flag == 0)
			{
                g_data->current_state = STATE_WIN_MENU;
				g_data->win_flag = 1;
			}
            else if (gameover(g_data->grid))
                g_data->current_state = STATE_GAMEOVER;
        }
    }
	if (g_data->current_state == STATE_WIN_MENU)
	{
		if (g_data->key == 'p')
			g_data->current_state = STATE_PLAYING;
	}
}