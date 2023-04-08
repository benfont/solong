/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:47:00 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/04 17:15:44 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
 *verifica la cantidad de 'P','E' y 'C'
 */
int	check_items(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	game->player = 0;
	game->exit = 0;
	game->collect = 0;
	while (game->map[col])
	{
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
	check_items_error(game);
	return (0);
}

/*
 * verifica el numero correccito de 'P', 'C' y 'E'
*/
void	check_items_error(t_game *game)
{
	if (game->player != 1 || (game->exit != 1 || game->collect < 1))
	{
		write (2, "Error\nCheck items error\n", 24);
		exit(-1);
	}
	game->collect_cp = game->collect;
	get_pos_player(game);
}
/*
 * obtener la posicion del jugador en el mapa
 */

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
				game->player_x = col;
				game->player_y = fil;
			}
			fil++;
		}
		col++;
		fil = 0;
	}
}
