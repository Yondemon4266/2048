/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:27:16 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 23:41:08 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	key_hook(t_game_data *g_data)
{
	if (g_data->key == 'q' || g_data->key == 'Q' || g_data->key == 27)
	{
		g_data->game_running = 0;
		return (-1);
	}

	if (g_data->key == KEY_RESIZE)
	{
		calculate_dimensions(g_data);
		return (0);
	}
	if (g_data->pause_game)
		return (0);
	switch (g_data->key)
	{
	case KEY_LEFT:
		return (going_left(&g_data->grid));
	case KEY_RIGHT:
		return (going_right(&g_data->grid));
	case KEY_UP:
		return (going_up(&g_data->grid));
	case KEY_DOWN:
		return (going_down(&g_data->grid));
	default:
		return (-1);
	}
	return (-4);
}