/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:21:55 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/25 20:10:18 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nNo read file", 18);
		exit(-1);
	}
	line = get_next_line(fd);
	if(!line)
	{
		write(2, "Error\nNo map", 13);
		exit(-1);
	}
	game->map_raw = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		game->map_raw = ft_strjoin(game->map_raw, line);
	}
	free(line);
	close (fd);
}

void	ft_create_map(t_game *game)
{
	game->map = ft_split(game->map_raw, '\n');
}

void	ft_width(t_game *game)
{
	int		count1;

	count1 = 0;
	while (game->map_raw[count1] != '\n' && game->map_raw[count1] != '\0')
		count1++;
	game->width = count1;
}

void	ft_height(t_game *game)
{
	int		count1;
	int		count2;
	
	count1 = 0;
	count2 = 0;
	while (game->map[count2] != NULL)
	{
		while (game->map[count2][count1] != '\n' && game->map[count2][count1] != '\0')
		{
			count1++;
		}
		count1 = 0;
		count2++;
	}
	game->height = count2;
}
