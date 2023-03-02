/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:09 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/02 20:03:39 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_game *game)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	printf("Entramos en la funcion checkrectangle\n");
	while (game->map[col][fil])
	{
		printf("Entramos en el while de col < width\n");
		printf("El col vale: %d, y el fil vale: %d\n", col, fil);
		while (game->map[col][fil])
		{
			fil++;
			printf("Entramos en el while del fil\n");
			printf("El col vale: %d, y el fil vale: %d\n", col, fil);
		}
		if (fil == game->width)
			printf("Vamos bien\n");
		if (fil != game->width)
		{
			write (2, "Error\nIt's not a rectangle\n", 28);
			return (-1);
		}
	return (0);
}
