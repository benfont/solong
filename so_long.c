/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/10 20:41:26 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"
/*
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
		game->map[game->player_x][game->player_y] = 'P';
		game->position = 'W';
	}
	else if (game->position == 'S')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x - 1;
		game->map[game->player_x][game->player_y] = 'P';
		game->position = 'S';
	}
}

static void	ft_movement_a_d(t_game *game)
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
		game->map[player_x][player_y] == '0';
		game->player_y = game->player_y + 1;
		game->map[player_x][player_y] == 'D';
		game->position = 'D';
	}
}

int	ft_movements(int keycode, t_game *game)
{
	game->position = ft_get_direction(keycode);
	if (keycode == 'W')
		printf("Me muevo arriba\n");
	if (keycode == 'A')
		printf("Me muevo a la izquierda\n");
	if (keycode == 'S')
		printf("Me muevo hacia abajo\n");
	if (keycode == 'D')
		printf("Me muevo a la derecha\n");
	return (0);
}
*/
int	ft_free_exit(t_game *game)
{
	(void)game;
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{

	t_game  game;

	check_errors(argc, argv);
	ft_read_map(argv, &game);
	ft_create_map(&game);
	ft_width(&game);
	ft_height(&game);
//	ft_barrier_height(&game);
//	ft_barrier_width(&game);
//	check_rectangle(&game);
	check_characters(&game);
	printf("my ancho is %d\n", game.width);
	printf("my largo is %d\n", game.height);
//	check_player(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
			game.height * SIZE, "El plan");
	ft_upload_images(&game);
	print_map(&game);
	mlx_hook(game.win_ptr, 17, 0, ft_free_exit, &game);
	mlx_hook(game.win_ptr, 2, 0, ft_movements, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
