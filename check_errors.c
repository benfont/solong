/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/02 18:22:40 by aitlopez         ###   ########.fr       */
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

int	content_map(t_game *game)
{
	int		count1;
	int		count2;

	count1 = 0;
	count2 = 0;
	while (count2 < game->height)
	{
		count1 = 0;
		while (count1 < game->width)
		{
			if (game->map[count1][count2] != '1' && game->map[count1][count2]
					&& game->map[count1][count2] != 'C'
					&& game->map[count1][count2] != 'E'
					&& game->map[count1][count2] != 'P'
					&& game->map[count1][count2] != '\0'
					&& game->map[count1][count2] != '\n')
				return (1);
			count1++;
		}
		count2++;
	}
	return (0);
}
