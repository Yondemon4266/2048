/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:27:16 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 16:57:24 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"


void    key_hook(t_game_data *g_data)
{
    switch (g_data->key)
    {
        case 'q':
            g_data->game_running = 0;
            break ;
        case 'Q':
            g_data->game_running = 0;
            break ;
        case KEY_LEFT:
            going_left(&g_data->grid);
            break ;
        case KEY_RIGHT:
            going_right(&g_data->grid);
            break ;
        case KEY_UP:
            going_up(&g_data->grid);
            break ;
        case KEY_DOWN:
            going_down(&g_data->grid);
            break ;
        case KEY_RESIZE:
            calculate_dimensions(g_data);
            break ;
        default:
            break ;
    }
}