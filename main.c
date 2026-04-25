/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:47:24 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 23:19:11 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_game_data(t_game_data *g_data)
{
	g_data->nb_of_cell = 4;
	g_data->game_running = 1;
	g_data->margin = 1;
	g_data->grid.row = g_data->nb_of_cell;
	g_data->grid.column = g_data->nb_of_cell;
	add_number(&g_data->grid, get_new_pos(g_data->grid));
	add_number(&g_data->grid, get_new_pos(g_data->grid));
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
	while (g_data.game_running)
	{
        clear();
		if (!gameover(g_data.grid))
		{
            draw_board(&g_data);
            check_display_win(&g_data);
			refresh();
			g_data.key = getch();
			reset_merged(&g_data.grid);
			if (key_hook(&g_data) <= 0)
				continue ;
			add_number(&g_data.grid, get_new_pos(g_data.grid));
		}
		else
			break ;
	}

	endwin();
	return (0);
}