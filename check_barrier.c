/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_barrier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:58:07 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/28 20:57:55 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_barrier_width(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	printf("Este es el width %d\n", game->width);
	while (count1 < game->width)
	{
		if (game->map[0][count1] != '1')
		{
			return (-1);
		}
		printf("Estoy en 1\n");
		count1++;
	}
//	printf("Este es el contador cuando sale: %d\n", count1);
	if (count1 != game->width)
	{
//		printf("Me meto aqui\n");
		return (-1);
	}
	count2 = 0;
//	printf("Este es el width %d\n", game->width);
	while (count2 < game->width)
	{
//		printf("Al menos entro una vez?\n");
		if (game->map[game->height -1][count2] != '1')
		{
//		printf("Este es el Caracter que encuentra: %c\n", game->map[game->width -1][count2]);
			return (-1);
		}
		count2++;
		printf("Estoy en 2\n");
	}
	if (count2 != game->height)
		return (-1);
	return (0);
}

int	ft_barrier_height(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	printf("este es el height %d\n", game->height);
	while (count1 < game->height)
	{
		if (game->map[count1][0] != '1')
			return (-1);
		printf("estoy en 1\n");
		count1++;
	}
	if (count1 != game->height)
	{
//		printf("me meto aquihey\n");
		return (-1);
	}
	count2 = 0;
	while (count2 < game->height)
	{
		if (game->map[count2][game->width -1] != '1')
		{
			printf("hey2\n");
			return (-1);
		}
		count2++;
		printf("estoy en dos\n");
	}
	if (count2 != game->width)
	{
		printf("me meto aqui\n");
		return (-1);
	}
	return (0);
}
