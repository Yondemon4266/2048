
#include "../game.h"

int	get_center_offset(int container_size, int item_size)
{
	if (container_size <= item_size)
		return (0);
	return ((container_size - item_size) / 2);
}

void	calculate_dimensions(t_game_data *g_data)
{
	int	ideal_height;
	int	ideal_width;

	ideal_height = LINES / g_data->nb_of_cell;
	ideal_width = ideal_height * 2;
	if ((ideal_width * g_data->nb_of_cell) > COLS)
	{
		ideal_width = COLS / g_data->nb_of_cell;
		ideal_height = ideal_width / 2;
	}
	g_data->cell_height = ideal_height - g_data->margin;
	g_data->cell_width = ideal_width - (g_data->margin * 2);

	if (g_data->cell_height < 1 || g_data->cell_width < 4)
		g_data->pause_game = 1;
	else
		g_data->pause_game = 0;
	g_data->board_height = g_data->cell_height * g_data->nb_of_cell;
	g_data->board_width = g_data->cell_width * g_data->nb_of_cell;
	g_data->start_y = get_center_offset(LINES, g_data->board_height);
	g_data->start_x = get_center_offset(COLS, g_data->board_width);
}

int	ncurses_print_nbr(int nb, int x, int y)
{
	if (nb < 0)
	{
		mvaddch(y, x, '-');
		nb = -nb;
		x++;
	}
	if (nb >= 10)
	{
		x = ncurses_print_nbr(nb / 10, x, y);
	}
	if (nb != 0)
		mvaddch(y, x, (nb % 10) + '0');
	else
		mvaddch(y, x, ' ');
	return (x + 1);
}

int	count_len_number(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}
