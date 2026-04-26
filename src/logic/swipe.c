/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:57:25 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/26 16:51:00 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	going_up(t_grid *grid)
{
	int	moved;
	int	y;
	int	x;
	int	index;

	moved = 0;
	y = 0;
	while (y < grid->row)
	{
		x = 1;
		while (x < grid->column)
		{
			index = 0;
			if (grid->cell_grid[x][y].value != 0)
			{
				while (x - index - 1 >= 0 && grid->cell_grid[x - index
					- 1][y].value == 0)
				{
					grid->cell_grid[x - index - 1][y].value += grid->cell_grid[x
						- index][y].value;
					grid->cell_grid[x - index][y].value = 0;
					moved++;
					index++;
				}
				if (x - index - 1 >= 0 && (grid->cell_grid[x - index
						- 1][y].value == grid->cell_grid[x - index][y].value)
					&& grid->cell_grid[x - index - 1][y].merged == 0)
				{
					grid->cell_grid[x - index - 1][y].value += grid->cell_grid[x
						- index][y].value;
					grid->score += grid->cell_grid[x - index - 1][y].value;
					grid->cell_grid[x - index - 1][y].merged++;
					grid->cell_grid[x - index][y].value = 0;
					moved++;
				}
			}
			x++;
		}
		y++;
	}
	return (moved);
}

int	going_down(t_grid *grid)
{
	int	moved;
	int	y;
	int	x;
	int	index;

	moved = 0;
	y = 0;
	while (y < grid->row)
	{
		x = grid->column - 2;
		while (x >= 0)
		{
			index = 0;
			if (grid->cell_grid[x][y].value != 0)
			{
				while (x + index + 1 <= grid->column - 1 && grid->cell_grid[x
					+ index + 1][y].value == 0)
				{
					grid->cell_grid[x + index + 1][y].value += grid->cell_grid[x
						+ index][y].value;
					grid->cell_grid[x + index][y].value = 0;
					moved++;
					index++;
				}
				if (x + index + 1 <= grid->column - 1 && (grid->cell_grid[x
						+ index + 1][y].value == grid->cell_grid[x
						+ index][y].value) && grid->cell_grid[x + index
					+ 1][y].merged == 0)
				{
					grid->cell_grid[x + index + 1][y].value += grid->cell_grid[x
						+ index][y].value;
					grid->score += grid->cell_grid[x + index + 1][y].value;
					grid->cell_grid[x + index + 1][y].merged++;
					grid->cell_grid[x + index][y].value = 0;
					moved++;
				}
			}
			x--;
		}
		y++;
	}
	return (moved);
}

int	going_left(t_grid *grid)
{
	int	moved;
	int	x;
	int	y;
	int	index;

	moved = 0;
	x = 0;
	while (x < grid->column)
	{
		y = 1;
		while (y < grid->row)
		{
			index = 0;
			if (grid->cell_grid[x][y].value != 0)
			{
				while (y - index - 1 >= 0 && grid->cell_grid[x][y - index
					- 1].value == 0)
				{
					grid->cell_grid[x][y - index - 1].value
						+= grid->cell_grid[x][y - index].value;
					grid->cell_grid[x][y - index].value = 0;
					moved++;
					index++;
				}
				if (y - index - 1 >= 0 && (grid->cell_grid[x][y - index
						- 1].value == grid->cell_grid[x][y - index].value)
					&& grid->cell_grid[x][y - index - 1].merged == 0)
				{
					grid->cell_grid[x][y - index - 1].value
						+= grid->cell_grid[x][y - index].value;
					grid->score += grid->cell_grid[x][y - index - 1].value;
					grid->cell_grid[x][y - index - 1].merged++;
					grid->cell_grid[x][y - index].value = 0;
					moved++;
				}
			}
			y++;
		}
		x++;
	}
	return (moved);
}

int	going_right(t_grid *grid)
{
	int	moved;
	int	x;
	int	y;
	int	index;

	moved = 0;
	x = 0;
	while (x < grid->column)
	{
		y = grid->row - 2;
		while (y >= 0)
		{
			index = 0;
			if (grid->cell_grid[x][y].value != 0)
			{
				while (y + index + 1 <= grid->row - 1 && grid->cell_grid[x][y
					+ index + 1].value == 0)
				{
					grid->cell_grid[x][y + index + 1].value
						+= grid->cell_grid[x][y + index].value;
					grid->cell_grid[x][y + index].value = 0;
					moved++;
					index++;
				}
				if (y + index + 1 <= grid->row - 1 && (grid->cell_grid[x][y
						+ index + 1].value == grid->cell_grid[x][y
						+ index].value) && grid->cell_grid[x][y + index
					+ 1].merged == 0)
				{
					grid->cell_grid[x][y + index + 1].value
						+= grid->cell_grid[x][y + index].value;
					grid->score += grid->cell_grid[x][y + index + 1].value;
					grid->cell_grid[x][y + index + 1].merged++;
					grid->cell_grid[x][y + index].value = 0;
					moved++;
				}
			}
			y--;
		}
		x++;
	}
	return (moved);
}
