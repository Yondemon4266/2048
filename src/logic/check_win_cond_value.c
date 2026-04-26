/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_cond_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluslu <aluslu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 22:21:27 by aluslu            #+#    #+#             */
/*   Updated: 2026/04/26 13:04:40 by aluslu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	check_win_cond_value(void)
{
	long long min = 2;
	long long win_val = (long long)WIN_VALUE;

	if (win_val < min)
		return (-1);
	if (win_val > INT_MAX)
		return (-1);
	while (min < win_val)
	{
		min *= 2;
		if (min > INT_MAX || min > win_val)
			return (-1);
		if (min == win_val)
			return (1);
	}
	return (-1);
}