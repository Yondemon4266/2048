/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:26:29 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/25 23:37:29 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static void	draw_board_lines(t_game_data *g_data)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= g_data->nb_of_cell)
	{
		x = 0;
		while (x < g_data->board_width)
		{
			mvprintw(g_data->start_y + (y * g_data->cell_height),
				g_data->start_x + x, "-");
			x++;
		}
	}
}

static void	draw_board_cols(t_game_data *g_data)
{
	int	y;
	int	x;

	x = -1;
	while (++x <= g_data->nb_of_cell)
	{
		y = 0;
		while (y <= g_data->board_height)
		{
			mvprintw(g_data->start_y + y, g_data->start_x + (x
					* g_data->cell_width), "|");
			y++;
		}
	}
}

static void	draw_numbers(t_game_data *g_data)
{
	int	y;
	int	x;
	int	value;
	int	len_value;
	int	centered_x;
	int	centered_y;

	y = 0;
	while (y < g_data->nb_of_cell)
	{
		x = 0;
		while (x < g_data->nb_of_cell)
		{
			value = g_data->grid.cell_grid[x][y].value;
			len_value = count_len_number(value);
			centered_x = g_data->start_x + (g_data->cell_width * y)
				+ get_center_offset(g_data->cell_width, len_value);
			centered_y = g_data->start_y + (g_data->cell_height * x)
				+ (g_data->cell_height / 2);
			ncurses_print_nbr(value, centered_x, centered_y);
			x++;
		}
		y++;
	}
}

void	draw_board(t_game_data *g_data)
{
	if (g_data->cell_height < 1 || g_data->cell_width < 4)
	{
		int	centered_x = get_center_offset(COLS, 18);
		int	centered_y = get_center_offset(LINES, 1);

		mvprintw(centered_y, centered_x, "Terminal too small");
		return ;
	}
	if (g_data->pause_game != 0)
		g_data->pause_game = 0;
	draw_board_lines(g_data);
	draw_board_cols(g_data);
	draw_numbers(g_data);
}
