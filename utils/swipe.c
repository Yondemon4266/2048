/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:57:25 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/25 15:23:20 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int    going_left(t_grid *grid)
{
    int moved = 0;
    int y = 0;
    
    while (y < grid->row)
    {
        int x = 1;
        while (x < grid->column)
        {
            int index = 0;
            if (grid->cell_grid[x][y].value != 0)
            {
                while (grid->cell_grid[x - index - 1][y].value == 0)
                {
                    grid->cell_grid[x - index - 1][y].value += grid->cell_grid[x - index][y].value;    
                    grid->cell_grid[x - index][y].value = 0;
                    moved++;
                    index++;
                }
                if ((grid->cell_grid[x - index - 1][y].value == grid->cell_grid[x - index][y].value)
                && grid->cell_grid[x - index - 1][y].merged == 0)
                {
                    grid->cell_grid[x - index - 1][y].value += grid->cell_grid[x - index][y].value;
                    grid->cell_grid[x - index][y].value = 0;
                }
                x++;
            }
        }
        y++;
    }
    return (moved);
}