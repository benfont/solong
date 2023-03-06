/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:21:55 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/06 18:52:13 by aitlopez         ###   ########.fr       */
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
	int		fil;

	fil = 0;
	while (game->map_raw[fil] != '\n' && game->map_raw[fil] != '\0')
		fil++;
	game->width = fil;
}

void	ft_height(t_game *game)
{
	int		fil;
	int		col;
	
	fil = 0;
	col = 0;
	while (game->map[col] != NULL)
	{
		while (game->map[col][fil] != '\n' && game->map[col][fil] != '\0')
		{
			fil++;
		}
		fil = 0;
		col++;
	}
	game->height = col;
}
