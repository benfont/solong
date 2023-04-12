/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:35:05 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/12 18:17:14 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
 * verifica si el jugador ha llegado a la salida
 */
int	can_exit(t_game *game)
{
	if (game->position == 'W' && (game->map[game->player_x -1][game->player_y]
		== 'E'))
		you_win(game);
	if (game->position == 'S' && (game->map[game->player_x +1][game->player_y]
		== 'E'))
		you_win(game);
	if (game->position == 'A' && (game->map[game->player_x][game->player_y -1]
		== 'E'))
		you_win(game);
	if (game->position == 'D' && (game->map[game->player_x][game->player_y +1]
		== 'E'))
		you_win(game);
	return (0);
}

void	you_win(t_game *game)
{
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
		15, 66000000, "CONGRATULATIONS");
	game->map[game->player_x][game->player_y - 1] = '1';
	game->map[game->player_x][game->player_y + 1] = '1';
	game->map[game->player_x - 1][game->player_y] = '1';
	game->map[game->player_x + 1][game->player_y] = '1';
}
/*
 * libera memoria asignada para el mapa y sale del programa
 */

int	free_exit(t_game *game)
{
	free_map(game);
	exit(1);
	return (0);
}
