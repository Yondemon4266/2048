/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:27:16 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 15:11:38 by alemyre          ###   ########.fr       */
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
            break ;
        case KEY_RIGHT:
            break ;
        case KEY_UP:
            break ;
        case KEY_DOWN:
            break ;
        case KEY_RESIZE:
            calculate_dimensions(g_data);
            break ;
        default:
            break ;
    }
}