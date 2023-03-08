/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:10:03 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/08 17:19:05 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//KEYCODE QUE CONECTA UNA TECLA DEL TECLADO CON LO QUE RECIBES
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

static void	ft_movements_w_s(t_game *game)
{
	if (game->player_position = 'W')
		
}
//movimiento
int	ft_movements(int keycode, t_game *game)
{
	game->position = ft_get_direction(keycode);
	if (position == 'W')
		printf("Me muevo arriba\n");
	if (position == 'A')
		printf("Me muevo a la izquierda\n");
	if (position == 'S')
		printf("Me muevo hacia abajo\n");
	if (position == 'D')
		printf ("Me muevo hacia la derecha\n");
	return (0);
}