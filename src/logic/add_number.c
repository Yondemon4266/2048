/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:23:31 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/26 12:54:01 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	get_new_pos(t_grid grid)
{
	int	zeros;

	zeros = count_zeros(grid);
	return (rand() % zeros);
}

void	add_number(t_grid *grid, int pos)
{
	int y = 0;
	int index = 0;

	int random = rand() % 10;
	int value = 0;

	if (random == 4)
		value = 4;
	else
		value = 2;

	while (y < grid->row)
	{
		int x = 0;
		while (x < grid->column)
		{
			if (grid->cell_grid[x][y].value == 0)
			{
				if (pos == index)
				{
					grid->cell_grid[x][y].value = value;
					return ;
				}
				else
					index++;
			}
			x++;
		}
		y++;
	}
}