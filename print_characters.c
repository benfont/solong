/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:10:49 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/23 19:35:54 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//esta funcion convierte los char en imagen
void	print_barrier(t_game *game, int col, int fil)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, (fil * SIZE), (col * SIZE));
}

void	print_espacio(t_game *game, int col, int fil)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[1].img_ptr, (fil * SIZE), (col * SIZE));
}

void	print_coleccionable(t_game *game, int col, int fil)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[2].img_ptr, (fil * SIZE), (col * SIZE));
}

void	print_heroe_w(t_game *game, int col, int fil)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[3].img_ptr, (fil * SIZE), (col * SIZE));
}

void	print_exit(t_game *game, int col, int fil)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[4].img_ptr, (fil * SIZE), (col * SIZE));
}
