/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:27:16 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 16:45:04 by alemyre          ###   ########.fr       */
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
            case 'm':       g_data->current_state = STATE_MENU; break;
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
    if (g_data->current_state == STATE_MENU)
    {   
        switch (g_data->key)
        {
            case KEY_UP:
                if (g_data->menu_data.selection - 1 < 0)
                    g_data->menu_data.selection = g_data->menu_data.element_count - 1;
                else
                    g_data->menu_data.selection--;
                break;
            
            case KEY_DOWN:
                if (g_data->menu_data.selection + 1 > g_data->menu_data.element_count - 1)
                    g_data->menu_data.selection = 0;
                else
                    g_data->menu_data.selection++;
                break;

            case 10:
                if (g_data->started)
                {
                    if (g_data->menu_data.selection == 0)
                        g_data->current_state = STATE_PLAYING;
                    else if (g_data->menu_data.selection == 1)
                    {
                        reset_game_data(g_data);
                        g_data->current_state = STATE_PLAYING;
                    }
                    else if (g_data->menu_data.selection == 2)
                        g_data->current_state = STATE_QUIT;
                }
                else
                {
                    if (g_data->menu_data.selection == 0)
                    g_data->current_state = STATE_PLAYING;
                    else if (g_data->menu_data.selection == 1)
                    g_data->current_state = STATE_QUIT;
                }
                break;
        }
    }
}