/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/04 20:43:33 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{

	t_game  game;

	check_errors(argc, argv);
	ft_read_map(argv, &game);
	ft_create_map(&game);
	ft_width(&game);
	ft_height(&game);
	ft_barrier_height(&game);
	ft_barrier_width(&game);
	check_rectangle(&game);
	check_characters(&game);
	printf("my ancho is %d\n", game.width);
	printf("my largo is %d\n", game.height);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.height * SIZE,
			game.width * SIZE, "Alice in wonderland");
	ft_upload_images(&game);
	ft_print_map(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
