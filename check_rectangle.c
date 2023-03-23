/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:09 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/23 15:53:38 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_len_width(t_game *game)
{
	int		col;
	int		lencol1;
	int		lencol2;

	col = 0;
	lencol1 = ft_strlen(game->map[col]);
	while (game->map[col])
	{
		lencol2 = ft_strlen(game->map[col]);
		if (lencol1 != lencol2)
		{
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
	while (game->map[col])
	{
		while (game->map[col][fil])
			fil++;
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
