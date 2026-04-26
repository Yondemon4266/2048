/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_finished.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:41:52 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/26 13:44:09 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

static int	going_up_read(t_grid grid)
{
	int	moved;
	int	y;
	int	x;
	int	index;

	moved = 0;
	y = 0;
	while (y < grid.row)
	{
		x = 1;
		while (x < grid.column)
		{
			index = 0;
			if (grid.cell_grid[x][y].value != 0)
			{
				while (x - index - 1 >= 0 && grid.cell_grid[x - index
					- 1][y].value == 0)
				{
					grid.cell_grid[x - index - 1][y].value += grid.cell_grid[x
						- index][y].value;
					grid.cell_grid[x - index][y].value = 0;
					moved++;
					index++;
				}
				if (x - index - 1 >= 0 && (grid.cell_grid[x - index
						- 1][y].value == grid.cell_grid[x - index][y].value)
					&& grid.cell_grid[x - index - 1][y].merged == 0)
				{
					grid.cell_grid[x - index - 1][y].value += grid.cell_grid[x
						- index][y].value;
					grid.cell_grid[x - index][y].value = 0;
					moved++;
				}
			}
			x++;
		}
		y++;
	}
	return (moved);
}

static int	going_down_read(t_grid grid)
{
	int	moved;
	int	y;
	int	x;
	int	index;

	moved = 0;
	y = 0;
	while (y < grid.row)
	{
		x = grid.column - 2;
		while (x >= 0)
		{
			index = 0;
			if (grid.cell_grid[x][y].value != 0)
			{
				while (x + index + 1 <= grid.column - 1 && grid.cell_grid[x
					+ index + 1][y].value == 0)
				{
					grid.cell_grid[x + index + 1][y].value += grid.cell_grid[x
						+ index][y].value;
					grid.cell_grid[x + index][y].value = 0;
					moved++;
					index++;
				}
				if (x + index + 1 <= grid.column - 1 && (grid.cell_grid[x
						+ index + 1][y].value == grid.cell_grid[x
						+ index][y].value) && grid.cell_grid[x + index
					+ 1][y].merged == 0)
				{
					grid.cell_grid[x + index + 1][y].value += grid.cell_grid[x
						+ index][y].value;
					grid.cell_grid[x + index][y].value = 0;
					moved++;
				}
			}
			x--;
		}
		y++;
	}
	return (moved);
}

static int	going_left_read(t_grid grid)
{
	int	moved;
	int	x;
	int	y;
	int	index;

	moved = 0;
	x = 0;
	while (x < grid.column)
	{
		y = 1;
		while (y < grid.row)
		{
			index = 0;
			if (grid.cell_grid[x][y].value != 0)
			{
				while (y - index - 1 >= 0 && grid.cell_grid[x][y - index
					- 1].value == 0)
				{
					grid.cell_grid[x][y - index - 1].value
						+= grid.cell_grid[x][y - index].value;
					grid.cell_grid[x][y - index].value = 0;
					moved++;
					index++;
				}
				if (y - index - 1 >= 0 && (grid.cell_grid[x][y - index
						- 1].value == grid.cell_grid[x][y - index].value)
					&& grid.cell_grid[x][y - index - 1].merged == 0)
				{
					grid.cell_grid[x][y - index - 1].value
						+= grid.cell_grid[x][y - index].value;
					grid.cell_grid[x][y - index].value = 0;
					moved++;
				}
			}
			y++;
		}
		x++;
	}
	return (moved);
}

static int	going_right_read(t_grid grid)
{
	int	moved;
	int	x;
	int	y;
	int	index;

	moved = 0;
	x = 0;
	while (x < grid.column)
	{
		y = grid.row - 2;
		while (y >= 0)
		{
			index = 0;
			if (grid.cell_grid[x][y].value != 0)
			{
				while (y + index + 1 <= grid.row - 1 && grid.cell_grid[x][y
					+ index + 1].value == 0)
				{
					grid.cell_grid[x][y + index + 1].value
						+= grid.cell_grid[x][y + index].value;
					grid.cell_grid[x][y + index].value = 0;
					moved++;
					index++;
				}
				if (y + index + 1 <= grid.row - 1 && (grid.cell_grid[x][y
						+ index + 1].value == grid.cell_grid[x][y
						+ index].value) && grid.cell_grid[x][y + index
					+ 1].merged == 0)
				{
					grid.cell_grid[x][y + index + 1].value
						+= grid.cell_grid[x][y + index].value;
					grid.cell_grid[x][y + index].value = 0;
					moved++;
				}
			}
			y--;
		}
		x++;
	}
	return (moved);
}

int	is_win(t_grid grid)
{
	int	x;
	int	y;

	y = 0;
	while (y < grid.row)
	{
        x = 0;
		while (x < grid.column)
		{
			if (grid.cell_grid[x][y].value == grid.win_value)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	gameover(t_grid grid)
{
	if (going_left_read(grid) + going_right_read(grid) + going_down_read(grid) + going_up_read(grid) == 0)
		return (1);
	return (0);
}

