/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_characters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:10:49 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/04 20:40:57 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_barrier(t_game *game, int c1, int c2)
{
	printf("Voy a printar mi pared\n");
	printf("Mi c1 es %d y mi c2 es %d\n", c1, c2);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, (c1 * SIZE), (c2 * SIZE));
}
