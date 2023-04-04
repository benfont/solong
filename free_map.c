/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:13:06 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/03 18:11:48 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * libera memoria asignada dinamicamente en las struct del juego
 */
#include "so_long.h"

void	free_map(t_game *game)
{
	int		cont;

	cont = 0;
	if (game->map[cont])
	{
		write (2, "A limpiar\n", 10);
		while (game->map[cont])
		{
			free(game->map[cont]);
			cont++;
		}
		free(game->map);
	}
	if (game->map_raw)
		free(game->map_raw);
	if (game->imgs)
		free(game->imgs);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}
