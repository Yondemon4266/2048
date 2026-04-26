/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:35:36 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/25 16:55:50 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	count_zeros(t_grid grid)
{
	int res = 0;
	int y = 0;

	while (y < grid.row)
	{
		int x = 0;
		while (x < grid.column)
		{
			if (grid.cell_grid[x][y].value == 0)
				res++;
			x++;
		}
		y++;
	}

	return (res);
}