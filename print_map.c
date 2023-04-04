/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:59:41 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/03 18:42:42 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/**
 * @brief 
 * imprime y muestra el estado del mapa
 * @param game 
 */
void	print_map(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (game->map[col])
	{
		fil = 0;
		while (game->map[col][fil])
		{
			if (game->map[col][fil] == '1')
				print_barrier(game, col, fil);
			else if (game->map[col][fil] == '0')
				print_espacio(game, col, fil);
			else if (game->map[col][fil] == 'C')
				print_coleccionable(game, col, fil);
			else if (game->map[col][fil] == 'E')
				print_exit(game, col, fil);
			else if (game->map[col][fil] == 'P')
				print_heroe_w(game, col, fil);
			fil++;
		}
		col++;
	}
}
