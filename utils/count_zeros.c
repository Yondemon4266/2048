/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_zeros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 15:35:36 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/25 16:24:43 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int count_zeros(t_grid grid)
{
    int res = 0;
    int y = 0;
    
    while (y < grid.row)
    {
        int x = 1;
        while (x < grid.column)
        {
            if (grid.cell_grid[x][y].value = 0)
                res++;
        }
        y++;
    }

    return (res);
}