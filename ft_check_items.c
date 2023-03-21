/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_items.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:47:00 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/21 17:07:30 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_items(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	game->player = 0;
	while (game->map[col])
	{
		printf("entramos en check_items\n");
		fil = 0;
		while (game->map[col][fil])
		{
			if (game->map[col][fil] == 'P')
				game->player++;
			if (game->map[col][fil] == 'E')
				game->exit++;
			if (game->map[col][fil] == 'C')
				game->collect++;
			fil++;
		}
		col++;
	}
	printf("before items error\n");
	check_items_error(game);
	return (0);
}

/**
 *recoge los datos de check_items
 *
 * */
void	check_items_error(t_game *game)
{
	printf("1\n");
	if (game->player != 1 || (game->exit != 1 || game->collect < 1))
	{
		printf("player es: %i\n", game->player);
		printf("exit es: %i\n", game->exit);
		printf("collect es: %i\n", game->collect);
		write (2, "Error\nError\n", 12);
		exit(-1);
	}
	printf("before get_pos_player\n");
	get_pos_player(game);
}

void	get_pos_player(t_game *game)
{
	printf("2\n");
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
				game->player_x = col;
				game->player_y = fil;
			}
			fil++;
		}
		col++;
		fil = 0;
	}
	printf("3\n");
}
