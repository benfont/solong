/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:35:06 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/08 18:06:55 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

//esta es la funcion que necesito para cargar la imagen del mapa
void	ft_upload_images(t_game *game)
{
	int	height;
	int	width;

	game->imgs = malloc(sizeof(t_img) * (5));
	game->imgs[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/pared.xpm", &width, &height);
	game->imgs[0].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/espacio.xpm", &width, &height);
	game->imgs[1].data = (int *)mlx_get_data_addr(game->imgs[1].img_ptr,
			&game->imgs[1].bpp, &game->imgs[1].size_l, &game->imgs[1].endian);
	game->imgs[2].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/coleccionable.xpm", &width, &height);
	game->imgs[2].data = (int *)mlx_get_data_addr(game->imgs[2].img_ptr,
			&game->imgs[2].bpp, &game->imgs[2].size_l, &game->imgs[2].endian);
	game->imgs[3].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/heroe_w.xpm", &width, &height);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	game->imgs[4].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &width, &height);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr,
			&game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
}
