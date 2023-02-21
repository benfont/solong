/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:39:20 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/21 20:18:39 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	ft_read_map(char **argv, t_game game)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (!fd)
	{
		write(2, "Error\nNo read file", 18);
		exit(-1);
	}
	line = get_next_line(fd);
	if (!line)
		return (-1);
	map_raw = ft_strdup(line);
	while (line)
	{
		line = get_next_line(fd);
		map_raw = ft_strjoin(map_raw, line); 
	}
	free(line);
	return (f);
}

int	main(int argc, char **argv)
{
	check_errors(argc, argv);
}
