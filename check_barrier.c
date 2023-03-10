/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_barrier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:58:07 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/14 19:53:39 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_barrier_width(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	while (count1 < game->width)
	{
		if (game->map[0][count1] != '1')
		{
			return (-1);
		}
		count1++;
	}
	if (count1 != game->width)
	{
		return (-1);
	}
	count2 = 0;
	while (count2 < game->width)
	{
		if (game->map[game->height -1][count2] != '1')
		{
			return (-1);
		}
		count2++;
		printf("Estoy en 2\n");
	}
	if (count2 != game->height)
		return (-1);
	return (0);
}

int	ft_barrier_height(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	while (count1 < game->height)
	{
		if (game->map[count1][0] != '1')
			return (-1);
		count1++;
	}
	if (count1 != game->height)
	{
		return (-1);
	}
	count2 = 0;
	while (count2 < game->height)
	{
		if (game->map[count2][game->width -1] != '1')
		{
			printf("hey2\n");
			return (-1);
		}
		count2++;
	}
	if (count2 != game->width)
	{
			return (-1);
	}
	return (0);
}
