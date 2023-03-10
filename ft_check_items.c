/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:47:00 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/10 21:38:09 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_items(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (game->map[col])
	{
		while (game->map[col][fil])
		{
			if (game->map[col][fil] == 'P')
				game->player++;
			if (game->map[col][fil] == 'E')
				game->exit++;
			if (game->map[col][fil] == 'C')
				game->coleccionable++;
			fil++;
		}
		col++;
		fil = 0;
	}
	if (game->player != 1 || game->exit != 1 || game->coleccionable < 1)
	{
		write (2, "Error\nError\n", 12);
		exit(-1);
	}
	get_pos_player(game);
}

void	get_pos_player(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (game->map[col])
	{
		while (game->map[col][fil])
		{
			if (game->map[col][fil] == 'P')
			{
				printf("Esto es game->map[col][fil] %c", game->map[col][fil]);
			   printf("col es %d\n", col);
		   		printf("fil es %d\n", fil);	   
				game->player_x = col;
				game->player_y = fil;
			}
			fil++;
		}
		col++;
		fil = 0;
	}
}
