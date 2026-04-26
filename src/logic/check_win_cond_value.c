/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_cond_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 22:21:27 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 13:52:10 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"



void check_win_cond_value(t_grid *grid)
{
    long long win_val = (long long)WIN_VALUE;
    long long current = 2;
    int count_power = 1;
    int max_power = (BOARD_SIZE * BOARD_SIZE) + 1;

    if (win_val < 8)
    {
        grid->win_value = 2048;
        return ;
    }

    while (current < win_val)
    {
        current *= 2;
        count_power++;
    }

    if (current == win_val && count_power <= max_power)
    {
        grid->win_value = (int)win_val;
    }
    else
    {
		grid->win_value = 2048;
    }
}