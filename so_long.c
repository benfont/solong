/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/21 19:07:02 by aitlopez         ###   ########.fr       */
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
	game.cp_map = copy_map(&game);
	game.cp_map2 = copy_map(&game);
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
