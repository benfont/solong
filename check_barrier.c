/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_barrier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:58:07 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/23 18:59:17 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//si el mapa no esta rodeado de '1' devuelve error
int	barrier_width(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	while (count1 < game->width)
	{
		if (game->map[0][count1] != '1')
			error_message();
		count1++;
	}
	count2 = 0;
	while (count2 < game->width)
	{
		if (game->map[game->height - 1][count2] != '1')
			error_message();
		count2++;
	}
	return (0);
}

int	barrier_height(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	while (count1 < game->height)
	{
		if (game->map[count1][0] != '1')
			error_message();
		count1++;
	}
	count2 = 0;
	while (count2 < game->height)
	{
		if (game->map[count2][game->width - 1] != '1')
			error_message();
		count2++;
	}
	return (0);
}
