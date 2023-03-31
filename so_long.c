/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/31 20:09:49 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_errors(argc, argv);
	read_map(argv, &game);
	create_map(&game);
	width(&game);
	height(&game);
	check_call(&game);
//	check_characters(&game);
//	check_items(&game);
	barrier_height(&game);
//	check_len_width(&game);
//	check_len_height(&game);
	game.cp_map = copy_map(&game);
	game.cp_map2 = copy_map(&game);
	check_path(&game, game.player_x, game.player_y);
	if (game.collect_cp != 0)
	{
		write (2, "Error\nNot path between the player and the exit\n", 47);
		exit (-1);
	}
	check_exit(&game, game.player_x, game.player_y);
	if (game.exit != 0)
	{
		write (2, "Error\nThere's not a path between the p and the exit\n", 57);
		exit (-1);
	}
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
			game.height * SIZE, "El plan");
	upload_images(&game);
	print_map(&game);
	mlx_hook(game.win_ptr, 17, 0, free_exit, &game);
	mlx_hook(game.win_ptr, 2, 0, movements, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
/*
	printf("my ancho is %d\n", game.width);
	printf("my largo is %d\n", game.height);
	printf("my playes is in %d, %d\n", game.player_x, game.player_y);
*/
