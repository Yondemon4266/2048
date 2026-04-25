/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:27:16 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 22:02:36 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	key_hook(t_game_data *g_data)
{
	switch (g_data->key)
	{
	case 'q':
		g_data->game_running = 0;
		return (-1);
	case 'Q':
		g_data->game_running = 0;
		return (-1);
	case 27:
		g_data->game_running = 0;
		return (-1);
	case KEY_LEFT:
		return (going_left(&g_data->grid));
	case KEY_RIGHT:
		return (going_right(&g_data->grid));
	case KEY_UP:
		return (going_up(&g_data->grid));
	case KEY_DOWN:
		return (going_down(&g_data->grid));
	case KEY_RESIZE:
		calculate_dimensions(g_data);
		return (0);
	default:
		return (-1);
	}
	return (-4);
}