/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:41:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/29 18:13:17 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_w_s(t_game *game)
{
	char	cont_char;

	if (game->position == 'W' && (game->map[game->player_x -1][game->player_y]
		== '0' || (game->map[game->player_x -1][game->player_y] == 'C')))
	{
		if (game->map[game->player_x -1][game->player_y] == 'C')
			game->collect--;
		game->contador++;
		cont_char = ft_putnbr(game->contador);
		write (1, "\n", 1);
		return (1);
	}
	if (game->position == 'S' && (game->map[game->player_x +1][game->player_y]
		== '0' || (game->map[game->player_x +1][game->player_y] == 'C')))
	{
		if (game->map[game->player_x +1][game->player_y] == 'C')
			game->collect--;
		game->contador++;
		cont_char = ft_putnbr(game->contador);
		write (1, "\n", 1);
		return (1);
	}
	return (0);
}

int	can_move_a_d(t_game *game)
{
	char	cont_char;

	if (game->position == 'A' && (game->map[game->player_x][game->player_y -1]
		== '0' || (game->map[game->player_x][game->player_y -1] == 'C')))
	{
		if (game->map[game->player_x][game->player_y -1] == 'C')
			game->collect--;
		game->contador++;
		cont_char = ft_putnbr(game->contador);
		write (1, "\n", 1);
		return (1);
	}
	if (game->position == 'D' && (game->map[game->player_x][game->player_y +1]
		== '0' || (game->map[game->player_x][game->player_y +1] == 'C')))
	{
		if (game->map[game->player_x][game->player_y +1] == 'C')
			game->collect--;
		game->contador++;
		cont_char = ft_putnbr(game->contador);
		write (1, "\n", 1);
		return (1);
	}
	if (game->collect == 0)
		can_exit(game);
	return (0);
}
