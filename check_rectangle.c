/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:09 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/22 16:10:17 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_len_width(t_game *game)
{
	int		col;
	int		lencol1;
	int		lencol2;

	col = 0;
	printf("Entramos en check_len_width\n");
	lencol1 = ft_strlen(game->map[col]);
	while (game->map[col])
	{
		lencol2 = ft_strlen(game->map[col]);
		if (lencol1 != lencol2)
		{
			printf("hola\n");
			write (2, "Error\nNo es un rectangulo\n", 26);
			exit(-1);
		}
		col++;
	}
}

void check_len_height(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	printf("Este es el valor de WIDTH: %d\n", game->width);
	while (game->map[col])
	{
		while (game->map[col][fil])
		{
			fil++;
			printf("Este es el valor de fil: %i\n", fil);
		}
		if (fil != game->width)
		{
			write (2, "Error\nNo es un rectangulooo", 26);
			exit(-1);
		}
		else if (fil == game->width && col < game->height)
		{
			col++;
			fil = 0;
		}
	}
}
