/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:47:00 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/10 20:49:42 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (game->map[col])
	{
		while (game->map[col][fil])
		{
			fil++;
			if (game->map[col][fil] == 'P')
				game->player = game->player + 1;
		}
		col++;
		fil = 0;
	}
	return (0);
}

int	check_col(t_game *game)
{
	
}
