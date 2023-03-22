/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/22 18:25:50 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_errors(argc, argv);
	ft_read_map(argv, &game);
	ft_create_map(&game);
	ft_width(&game);
	ft_height(&game);
	check_characters(&game);
	printf("my ancho is %d\n", game.width);
	printf("my largo is %d\n", game.height);
	check_items(&game);
	printf("my playes is in %d, %d\n", game.player_x, game.player_y);
	check_len_width(&game);
	check_len_height(&game);
	game.cp_map = copy_map(&game);
	printf("Llego 1\n");
	game.cp_map2 = copy_map(&game);
	printf("Llego 2\n");
	game.mlx_ptr = mlx_init();
	printf("Llego 3\n");
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * SIZE,
			game.height * SIZE, "El plan");
	printf("Llego 4\n");
	ft_upload_images(&game);
	printf("Llego 5\n");
	print_map(&game);
	printf("Llego 6\n");
	mlx_hook(game.win_ptr, 17, 0, ft_free_exit, &game);
	printf("Llego 7\n");
	mlx_hook(game.win_ptr, 2, 0, ft_movements, &game);
	printf("Llego 8\n");
	mlx_loop(game.mlx_ptr);
	printf("Llego 9\n");
	return (0);
}
