/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:57:28 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/31 19:53:25 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	int		count;
	char	**copymap;

	count = 0;
	copymap = (char **)malloc(sizeof(char *) * (game->width + 1));
	if (!copymap)
		return (NULL);
	while (game->map[count])
	{
		copymap[count] = ft_strdup(game->map[count]);
		count++;
	}
	copymap[count] = NULL;
	game->exit = 1;
	return (copymap);
}

void	check_path(t_game *game, int col, int fil)
{
	if ((game->cp_map[col][fil] == 'V') || (game->cp_map[col][fil] == '1'
			|| game->cp_map[col][fil] == 'E'))
	{
		return ;
		// write(1, "Error\nNo hay camino posible hey\n", 32);
		// exit(-1);
	}
	if (game->cp_map[col][fil] == 'C')
	{
		game->collect_cp--;
		game->cp_map[col][fil] = 'V';
	}
	game->cp_map[col][fil] = 'V';
	check_path(game, col, fil + 1);
	check_path(game, col, fil - 1);
	check_path(game, col + 1, fil);
	check_path(game, col - 1, fil);
}

void	check_exit(t_game *game, int col, int fil)
{
	if ((game->cp_map2[col][fil] == 'V') || (game->cp_map2[col][fil] == '1'))
	{
		return ;
		//write(1, "Error\nNo hay camino posible\n", 28);
		//exit(-1);
	}
	if (game->cp_map2[col][fil] == 'E')
	{
		game->cp_map2[col][fil] = 'V';
		game->exit--;
	}
	game->cp_map2[col][fil] = 'V';
	check_exit(game, col, fil + 1);
	check_exit(game, col, fil - 1);
	check_exit(game, col + 1, fil);
	check_exit(game, col - 1, fil);
	game->contador = 0;
//	return (0);
}
