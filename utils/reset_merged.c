/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_merged.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:56:29 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/25 15:20:06 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void    reset_merged(t_grid *grid)
{
    int y = 0;
    
    while (y < grid->row)
    {
        int x = 0;
        while (x < grid->column)
        {
            grid->cell_grid[x][y].merged = 0;
            x++;
        }
        y++;
    }
}