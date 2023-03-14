/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:09 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/14 19:56:36 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
