/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:26:34 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/03 18:42:38 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/**
 * @brief Get the direction object
 * devuelve la direccion en la que se movera el jugador
 * @param keycode 
 * @param game 
 * @return char 
 */
static char	get_direction(int keycode, t_game *game)
{
	if (keycode == 13)
		return ('W');
	if (keycode == 0)
		return ('A');
	if (keycode == 1)
		return ('S');
	if (keycode == 2)
		return ('D');
	if (keycode == 53)
	{
		free_map(game);
		exit(-1);
	}
	return (0);
}
/**
 * @brief 
 * devuelve la direccion en la que se movera 'P'
 * @param game 
 */
static void	movement_w_s(t_game *game)
{
	if (game->position == 'W')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x -1;
		game->map[game->player_x][game->player_y] = 'P';
	}
	else if (game->position == 'S')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x +1;
		game->map[game->player_x][game->player_y] = 'P';
	}
}
/**
 * @brief 
 * devuelve la direccion en la se movera 'P'
 * @param game 
 */
static void	movement_a_d(t_game *game)
{
	if (game->position == 'A')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y -1;
		game->map[game->player_x][game->player_y] = 'P';
	}
	else if (game->position == 'D')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y + 1;
		game->map[game->player_x][game->player_y] = 'P';
	}
}
/**
 * @brief 
 * obtiene direccion del movimiento
 * verifica si 'P' puede moverse
 * realiza el movimiento
 * imprime el mapa actualizado
 * @param keycode 
 * @param game 
 * @return int 
 */
int	movements(int keycode, t_game *game)
{
	game->position = get_direction(keycode, game);
	if (keycode == 'W')
		write (2, "Me muevo hacia arriba\n", 22);
	if (keycode == 'S')
		write (2, "Me muevo hacia abajo\n", 21);
	if (keycode == 'A')
		write (2, "Me muevo hacia la izquierda\n", 24);
	if (keycode == 'D')
		write (2, "Me muevo hacia la derecha\n", 23);
	if ((can_move_w_s(game) == 1) || (can_move_a_d(game) == 1))
	{
		movement_w_s(game);
		movement_a_d(game);
		print_map(game);
	}
	return (0);
}
