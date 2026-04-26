/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:26:29 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 18:42:00 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static void	draw_board_lines(t_game_data *g_data)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= BOARD_SIZE)
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
	while (++x <= BOARD_SIZE)
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

static int get_color(int value)
{
	int ans = 0;

	while (value > 1)
	{
		value /= 2;
		ans++;
	}
	return (ans);
}

static void	draw_numbers(t_game_data *g_data)
{
	int	y = 0;
	while (y < BOARD_SIZE)
	{
		int x = 0;
		while (x < BOARD_SIZE)
		{
			int value = g_data->grid.cell_grid[x][y].value;
			int color = get_color(value);
			int pos_x = g_data->start_x + (g_data->cell_width * y);
			int pos_y = g_data->start_y + (g_data->cell_height * x);

			int i = 1;
			while (i < g_data->cell_height)
			{
				int j = 1;
				while (j < g_data->cell_width)
				{
					if (value == 0)
						ncurses_print_nbr(-1, pos_x + j, pos_y + i, 30, 0);
					else
						ncurses_print_nbr(-1, pos_x + j, pos_y + i, color, 0);
					j++;
				}
				i++;
			}

			if (value != 0)
			{
				int len_value = count_len_number(value);
				int ascii_width = (len_value * 5) + (len_value - 1); 
				int centered_x;
				int centered_y; 
				if (g_data->is_ascii)
				{
					centered_x = pos_x + get_center_offset(g_data->cell_width, ascii_width);
					centered_y = pos_y + get_center_offset(g_data->cell_height, 5);
				}
				else
				{
					centered_x = pos_x + get_center_offset(g_data->cell_width, len_value);
					centered_y = pos_y + get_center_offset(g_data->cell_height, 0);
				}

				ncurses_print_nbr(value, centered_x, centered_y, color, g_data->is_ascii);
			}
			x++;
		}
		y++;
	}
}

void	draw_board(t_game_data *g_data)
{

	draw_board_lines(g_data);
	draw_board_cols(g_data);
	draw_numbers(g_data);
	mvprintw(1, 1, "Score: %d", g_data->grid.score);
}
