/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:25:44 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/04 17:09:55 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * recorre la matriz
 * comprueba cada char de la matriz
 */
#include "so_long.h"

int	check_characters(t_game *game)
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
			if (game->map[col][fil] != '1' && game->map[col][fil]
					&& game->map[col][fil] != '0'
					&& game->map[col][fil] != 'C'
					&& game->map[col][fil] != 'E'
					&& game->map[col][fil] != 'P')
			{
				write (2, "Error\nWrong characters\n", 23);
				exit(-1);
			}
		}
		col++;
		fil = 0;
	}
	return (0);
}
