/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:26:34 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/13 21:54:19 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
//este archivo mueve el player en el map
static char	ft_get_direction(int keycode, t_game *game)
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

static void	ft_movement_w_s(t_game *game)
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

static void ft_movement_a_d(t_game *game)
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

int ft_can_move(t_game *game)
{
	if (game->position == 'W' && (game->map[game->player_x -1][game->player_y] == '0' || (game->map[game->player_x -1][game->player_y] == 'C')))
	{
		if (game->map[game->player_x -1][game->player_y] == 'C')
			game->collect--;
		game->contador++;
		printf("Mi jugador ha reccorido %d\n", game->contador);
//		printf("Nos quedan estos coleccionables: %d\n", game->collect);
		return (1);
	}
	if (game->position == 'S' && (game->map[game->player_x +1][game->player_y] == '0' || (game->map[game->player_x +1][game->player_y] == 'C')))
	{
		if (game->map[game->player_x +1][game->player_y] == 'C')
			game->collect--;
		game->contador++;
		printf("Mi jugador ha reccorido %d\n", game->contador);
//		printf("Nos quedan estos coleccionables: %d\n", game->collect);
		return (1);
	}
	if (game->position == 'A' && (game->map[game->player_x][game->player_y -1] == '0' || (game->map[game->player_x][game->player_y -1] == 'C')))
	{
		if (game->map[game->player_x][game->player_y -1] == 'C')
			game->collect--;
		game->contador++;
		printf("Mi jugador ha reccorido %d\n", game->contador);
//		printf("Nos quedan estos coleccionables: %d\n", game->collect);
		return (1);
	}
	if (game->position == 'D' && (game->map[game->player_x][game->player_y +1] == '0' || (game->map[game->player_x][game->player_y +1] == 'C')))
	{
		if (game->map[game->player_x][game->player_y +1] == 'C')
			game->collect--;
		game->contador++;
		printf("Mi jugador ha reccorido %d\n", game->contador);
//		printf("Nos quedan estos coleccionables: %d\n", game->collect);
		return (1);
	}
	if (game->collect == 0)
		ft_can_exit(game);
	return (0);
}

int	ft_can_exit(t_game *game)
{
//	printf("Aqui entro\n");
	if (game->position == 'W' && (game->map[game->player_x -1][game->player_y] == 'E'))
		you_win(game);
	if (game->position =='S' && (game->map[game->player_x +1][game->player_y] == 'E'))
  		you_win(game);
	if (game->position == 'A' && (game->map[game->player_x][game->player_y -1] == 'E'))
		you_win(game);
	if (game->position == 'D' && (game->map[game->player_x][game->player_y +1] == 'E'))
		you_win(game);
	return (0);
}

int	you_win(t_game *game)
{
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, "CONGRATULATIONS");
		return (1);
	}
	return (0);
}

int	ft_movements(int keycode, t_game *game)
{
	game->position = ft_get_direction(keycode, game);
	if (keycode == 'W')
		printf("Me muevo hacia arriba\n");
	if (keycode == 'S')
		printf("Me muevo hacia abajo\n");
	if (keycode == 'A')
		printf("Me muevo hacia la izquierda\n");
	if (keycode == 'D')
		printf("Me muevo hacia la derecha\n");
	if (ft_can_move(game) == 1)
	{
		ft_movement_w_s(game);
		ft_movement_a_d(game);
		print_map(game);
	}
	return (0);
}

int	ft_free_exit(t_game *game)
{
	free_map(game);
	exit(1);
	return (0);
}
