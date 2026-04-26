/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:47:24 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 16:42:51 by alemyre          ###   ########.fr       */
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

void	reset_game_data(t_game_data *g_data)
{
	reset_grid(&g_data->grid);
	g_data->grid.score = 0;
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	calculate_dimensions(g_data);
	g_data->current_state = STATE_MENU;
}

void	init_colors(void)
{
	start_color();
	use_default_colors();
	
	init_pair(30, COLOR_BLACK, 254);				// vide

	init_pair(1, COLOR_BLACK, 230);				// 2
	init_pair(2, COLOR_BLACK, 223);				// 4
	init_pair(3, COLOR_BLACK, 215);				// 8
	init_pair(4, COLOR_WHITE, 209);				// 16
	init_pair(5, COLOR_WHITE, 203);				// 32
	init_pair(6, COLOR_WHITE, 196);				// 64
	init_pair(7, COLOR_WHITE, 227);				// 128
	init_pair(8, COLOR_BLACK, 226);				// 256
	init_pair(9, COLOR_WHITE, 220);				// 512
	init_pair(10, COLOR_WHITE, 214);			// 1024
	init_pair(11, COLOR_BLACK, 208);			// 2048
	init_pair(12, COLOR_WHITE, 202);			// 4096
	init_pair(13, COLOR_WHITE, 196);			// 8192
	init_pair(14, COLOR_WHITE, 190);			// 16 384
	init_pair(15, COLOR_WHITE, 187);			// 32 768
	init_pair(16, COLOR_WHITE, 183);			// 65 536
	init_pair(17, COLOR_WHITE, 179);			// 131 072
	init_pair(18, COLOR_BLACK, 175);			// 262 144
	init_pair(19, COLOR_WHITE, 169);			// 524 288
	init_pair(20, COLOR_WHITE, 164);			// 1 048 576
	init_pair(21, COLOR_BLACK, 160);			// 2 097 152
	init_pair(22, COLOR_WHITE, 154);			// 4 194 304
	init_pair(23, COLOR_WHITE, 150);			// 8 388 608
	init_pair(24, COLOR_WHITE, 145);			// 16 777 216
	init_pair(25, COLOR_WHITE, 140);			// 33 554 432
	init_pair(26, COLOR_WHITE, 130);			// 67 108 864
}

int	main(void)
{
	t_game_data g_data = {0};
	srand(time(NULL));
	initscr();
	init_colors();
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