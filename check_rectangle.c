/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:09 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/21 20:37:45 by aitlopez         ###   ########.fr       */
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
		{
			if (game->map[col][fil] != fil)
			{
				write (2, "Error\nNo es un rectangulo", 26);
				exit(-1);
			}
			fil++;
		}
		col++;
		fil = 0;
	}
}

/*
int	check_rectangle(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (game->map[col][fil])
	{
		while (game->map[fil])
		{
			fil++;
		}
		if (fil != game->width)
		{
			write (2, "Error\nIt's not a rectangle\n", 28);
			return (-1);
		}
		col++;
		fil = 0;
	}
	return (0);
}
*/
