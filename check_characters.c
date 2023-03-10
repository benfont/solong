/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:25:44 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/10 20:38:12 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_characters(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	printf("Entramos en la funcion check characters\n");
	while (game->map[col])
	{
		while (game->map[col][fil])
		{
			fil++;
			if(game->map[col][fil] != '1' && game->map[col][fil]
					&& game->map[col][fil] != '0'
					&& game->map[col][fil] != 'C'
					&& game->map[col][fil] != 'E'
					&& game->map[col][fil] != 'P')
			{
				printf("hey\n");
				write (2, "Error\nWrong characters\n", 23);
				exit(-1);
//				return (-1);
			}
		}
		col++;
		fil = 0;
	}
	return (0);
}
