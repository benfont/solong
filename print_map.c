/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:59:41 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/04 20:39:51 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(t_game *game)
{
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;

	while(game->map[c1])
	{
		c2 = 0;
		while (game->map[c1][c2])
		{
			if (game->map[c1][c2] == '1')
				ft_print_barrier(game, c1, c2);
			c2++;
		}
		c1++;
	//	c2 = 0;
	}
}
