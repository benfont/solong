/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/27 17:43:39 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(int argc, char **argv)
{
	size_t	len;

	len = 0;
	(void) argv;
	if (argc != 2)
	{
		write (2, "Error\nBad arg number", 20);
		exit(-1);
	}
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".ber", 4))
	{
		write (2, "Error\nIncorrect extension", 25);
		exit(-1);	
	}
	return (0);
}

int	check_barrier(t_game *game)
{
	int		count;

	count = 0;
	while (count < game->width)
	{
		if (game->map[0][count] != '1')
			return (-1);
		if (game->map[game->height -1][count] != '1')
			return (-1);
		count++;
	}
	return (0);
}
