/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:47:24 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 13:54:53 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_game_data(t_game_data *g_data)
{
	g_data->nb_of_cell = BOARD_SIZE;
	g_data->margin = 1;
	g_data->grid.row = BOARD_SIZE;
	g_data->grid.column = BOARD_SIZE;
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	calculate_dimensions(g_data);
	g_data->current_state = STATE_MENU;
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
	init_game_data(&g_data);
	check_win_cond_value(&g_data.grid);
	while (g_data.current_state != STATE_QUIT)
	{
        clear();
		if (!is_terminal_valid(&g_data))
			handle_too_small_screen(&g_data);
		else
		{
			if (g_data.current_state == STATE_MENU)
				handle_menu(&g_data);
			else if (g_data.current_state == STATE_PLAYING)
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