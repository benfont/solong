/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:21:55 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/24 21:41:25 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_map(char **argv, t_game *game)
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
		game->map_raw = ft_strjoin(game->map_raw, fd);
	}
	free(line);
	return (fd);
}

size_t	ft_width(const char *fd, t_game *game)
{
	int		c;

	c = 0;
	while (fd[c] != '\0')
		c++;
	game->width = ft_strlen(game->width, c);
	return (c);
}
