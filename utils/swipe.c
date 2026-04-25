/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemyre <alemyre@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 14:57:25 by alemyre           #+#    #+#             */
/*   Updated: 2026/04/25 18:15:55 by alemyre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int    going_up(t_grid *grid)
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
                while (x - index - 1 >= 0 && grid->cell_grid[x - index - 1][y].value == 0)
                {
                    grid->cell_grid[x - index - 1][y].value += grid->cell_grid[x - index][y].value;    
                    grid->cell_grid[x - index][y].value = 0;
                    moved++;
                    index++;
                }
                if (x - index - 1 >= 0
                    && (grid->cell_grid[x - index - 1][y].value == grid->cell_grid[x - index][y].value)
                && grid->cell_grid[x - index - 1][y].merged == 0)
                {
                    grid->cell_grid[x - index - 1][y].value += grid->cell_grid[x - index][y].value;
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

int    going_down(t_grid *grid)
{
    int moved = 0;
    int y = 0;
    
    while (y < grid->row)
    {
        int x = grid->column - 2;
        while (x >= 0)
        {
            int index = 0;
            if (grid->cell_grid[x][y].value != 0)
            {
                while (x + index + 1 <= grid->column - 1 && grid->cell_grid[x + index + 1][y].value == 0)
                {
                    grid->cell_grid[x + index + 1][y].value += grid->cell_grid[x + index][y].value;    
                    grid->cell_grid[x + index][y].value = 0;
                    moved++;
                    index++;
                }
                if (x + index + 1 <= grid->column - 1 && (grid->cell_grid[x + index + 1][y].value == grid->cell_grid[x + index][y].value)
                && grid->cell_grid[x + index + 1][y].merged == 0)
                {
                    grid->cell_grid[x + index + 1][y].value += grid->cell_grid[x + index][y].value;
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


int    going_left(t_grid *grid)
{
    int moved = 0;
    int x = 0;
    
    while (x < grid->column)
    {
        int y = 1;
        while (y < grid->row)
        {
            int index = 0;
            if (grid->cell_grid[x][y].value != 0)
            {
                while (y - index - 1 >= 0 && grid->cell_grid[x][y - index - 1].value == 0)
                {
                    grid->cell_grid[x][y - index - 1].value += grid->cell_grid[x][y - index].value;    
                    grid->cell_grid[x][y - index].value = 0;
                    moved++;
                    index++;
                }
                if (y - index - 1 >= 0
                    && (grid->cell_grid[x][y - index - 1].value == grid->cell_grid[x][y - index].value)
                && grid->cell_grid[x][y - index - 1].merged == 0)
                {
                    grid->cell_grid[x][y - index - 1].value += grid->cell_grid[x][y - index].value;
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

int    going_right(t_grid *grid)
{
    int moved = 0;
    int x = 0;
    
    while (x < grid->column)
    {
        int y = grid->row - 2;
        while (y >= 0)
        {
            int index = 0;
            if (grid->cell_grid[x][y].value != 0)
            {
                while (y + index + 1 <= grid->row - 1 && grid->cell_grid[x][y + index + 1].value == 0)
                {
                    grid->cell_grid[x][y + index + 1].value += grid->cell_grid[x][y + index].value;    
                    grid->cell_grid[x][y + index].value = 0;
                    moved++;
                    index++;
                }
                if (y + index + 1 <= grid->row - 1
                    && (grid->cell_grid[x][y + index + 1].value == grid->cell_grid[x][y + index].value)
                && grid->cell_grid[x][y + index + 1].merged == 0)
                {
                    grid->cell_grid[x][y + index + 1].value += grid->cell_grid[x][y + index].value;
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
