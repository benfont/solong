/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:26:34 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/08 20:46:41 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static char	ft_get_direction(int keycode)
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
		return (-1);
	return (0);
}

static void	ft_movement_w_s(t_game *game)
{
	if (game->position == 'W')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x + 1;
		game->map[game->player_x][game->player_y] = 'W';
		game->position = 'W';
	}
	else if (game->position == 'S')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x - 1;
		game->map[game->player_x][game->player_y] = 'S';
		game->position = 'S';
	}
}

static void ft_movement_a_d(t_game *game)
{
	if (game->position == 'A')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y - 1;
		game->map[game->player_x][game->player_y] = 'A';
		game->position = 'A';
	}
	else if (game->position == 'D')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y + 1;
		game->map[game->player_x][game->player_y] = 'D';
		game->position = 'D';
	}
}

int	ft_movements(int keycode, t_game *game)
{
	game->position = ft_get_direction(keycode);
	if (keycode == 'W')
		printf("Me muevo hacia arriba\n");
	if (keycode == 'S')
		printf("Me muevo hacia abajo\n");
	if (keycode == 'A')
		printf("Me muevo hacia la izquierda\n");
	if (keycode == 'D')
		printf("Me muevo hacia la derecha\n");
	return (0);
}

int	ft_free_exit(t_game *game)
{
	(void)game;
	exit(1);
	return (0);
}