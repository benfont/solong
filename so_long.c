/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/08 22:39:59 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	init_game(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width * SIZE,
			game->height * SIZE, "El plan");
	upload_images(game);
	print_map(game);
	mlx_hook(game->win_ptr, 17, 0, free_exit, game);
	mlx_hook(game->win_ptr, 2, 0, movements, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void	ft_exit_collect(void)
{
	write (2, "Error\nNot path between the player and the exit\n", 47);
	exit (-1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_errors(argc, argv);
	read_map(argv, &game);
	create_map(&game);
	width(&game);
	height(&game);
	check_characters(&game);
	check_items(&game);
	barrier_height(&game);
	check_len_width(&game);
	check_len_height(&game);
	game.cp_map = copy_map(&game);
	game.cp_map2 = copy_map(&game);
	check_path(&game, game.player_x, game.player_y);
	if (game.collect_cp != 0)
		ft_exit_collect();
	check_exit(&game, game.player_x, game.player_y);
	if (game.exit != 0)
		ft_exit_collect();
	init_game(&game);
	return (0);
}
