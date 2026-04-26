/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:35:51 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/26 16:36:44 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	reset_grid(t_grid *grid)
{
	int y = 0;

	while (y < grid->row)
	{
		int x = 0;
		while (x < grid->column)
		{
			grid->cell_grid[x][y].value = 0;
			x++;
		}
		y++;
	}
}