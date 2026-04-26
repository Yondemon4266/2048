/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:47:24 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 11:33:21 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_game_data(t_game_data *g_data)
{
	g_data->nb_of_cell = 4;
	g_data->margin = 1;
	g_data->grid.row = g_data->nb_of_cell;
	g_data->grid.column = g_data->nb_of_cell;
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	g_data->current_state = STATE_PLAYING;
	calculate_dimensions(g_data);
}

int	main(void)
{
	t_game_data g_data = {0};
	srand(time(NULL));
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	set_escdelay(25);
	keypad(stdscr, TRUE);
	if (check_win_cond_value() == -1)
	{
		endwin();
		ft_putstr_fd(2, "Error, win value must be a power of 2 and a positive integer\n");
		return (-1);
	}
	init_game_data(&g_data);
	while (g_data.current_state != STATE_QUIT)
	{
        clear();
		if (!is_terminal_valid(&g_data))
			handle_too_small_screen(&g_data);
		else
		{
			if (g_data.current_state == STATE_PLAYING)
				handle_playing_state(&g_data);
			else if (g_data.current_state == STATE_WIN_MENU)
				handle_win_state(&g_data);
			else if (g_data.current_state == STATE_GAMEOVER)
				handle_gameover_state(&g_data);
		}
		refresh();
		g_data.key = getch();
		key_hook(&g_data);
	}

	endwin();
	return (0);
}