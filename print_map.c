/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:59:41 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/08 18:08:25 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				ft_print_barrier(game, col, fil);
			else if (game->map[col][fil] == '0')
				ft_print_espacio(game, col, fil);
			else if (game->map[col][fil] == 'C')
				ft_print_coleccionable(game, col, fil);
			else if (game->map[col][fil] == 'E')
				ft_print_exit(game, col, fil);
			else if (game->map[col][fil] == 'P')
				ft_print_exit(game, col, fil);
			fil++;
		}
		col++;
	}
}
