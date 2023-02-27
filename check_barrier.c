/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_barrier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:58:07 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/27 20:10:49 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_barrier_height(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	while (count1 < game->width)
	{
		if (game->map[count1][0] != '1')
			return (1);
		count1++;
	}
	printf("Este es el width %d\n", game->width);
	if (count1 != game->width)
		return (1);
	while (count1 < game->width)
	{
		if (game->map[count2][game->height - 1] != '1')
			return (1);
		count2++;
	}
	if (count2 != game->width)
		return (1);
	return (0);
}

int	ft_barrier_width(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	while (count1 < game->width)
	{
		if (game->map[count1][0] != '1')
			return (1);
		count1++;
	}
	if (count1 != game->width)
		return (1);
	while (count2 < game->width)
	{
		if (game->map[count2][game->height - 1] != '1')
			count2++;
		return (1);
	}
	if (count2 != game->width)
		return (1);
	return (0);
}
