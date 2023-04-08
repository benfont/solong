/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:21:55 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/04 17:12:44 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * leer y procesar mapa a partir de un archivo
 */
#include "so_long.h"

/**
 * @brief 
 * abre, lee el archivo y concatena cada linea leida
 * @param argv 
 * @param game 
 */

void	read_map(char **argv, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		no_read_file();
	line = get_next_line(fd);
	if (!line)
		no_map();
	game->map_raw = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			game->map_raw = ft_strjoin(game->map_raw, line);
	}
	free(line);
	close (fd);
}
/**
 * @brief Create a map object
 * divide la cadena map_raw utilizando ft_split
 * y lo almacena en game
 * @param game 
 */

void	create_map(t_game *game)
{
	game->map = ft_split(game->map_raw, '\n');
}
/**
 * @brief 
 * calcula anchura del mapa
 * @param game 
 */

void	width(t_game *game)
{
	int		fil;

	fil = 0;
	while (game->map_raw[fil] != '\n' && game->map_raw[fil] != '\0')
		fil++;
	game->width = fil;
}
/**
 * @brief 
 * calcula altura del mapa
 * @param game 
 */

void	height(t_game *game)
{
	int		fil;
	int		col;

	fil = 0;
	col = 0;
	while (game->map[col] != NULL)
	{
		while (game->map[col][fil] != '\n' && game->map[col][fil] != '\0')
			fil++;
		fil = 0;
		col++;
	}
	game->height = col;
}
