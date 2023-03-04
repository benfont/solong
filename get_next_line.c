/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:58:09 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/25 20:24:53 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define BUFFER_SIZE 1

char	*true_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

/*
 * elimina el caracter de nueva linea y cualquier espacio en blanco
*/
char	*ft_xtraspace(char *fed)
{
	int		i;
	char	*rest;

	i = 0;
	while (fed[i] != '\n' && fed [i])
		i++;
	if (!fed[i])
	{
		free(fed);
		return (NULL);
	}
	rest = ft_strdup(fed + i + (fed[i] == '\n'));
	free(fed);
	return (rest);
}

/*
 *	esta funcion lee datos de un fd en fragmentos de buffer_size
 *	y los agrega a una cadena existente
*/

char	*ft_read(int fd, char *fed)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (true_free(&fed));
	temp[0] = '\0';
	while (bytes > 0 && !ft_strchr(temp, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(fed);
			return (NULL);
		}
		if (bytes > 0)
		{
		temp[bytes] = '\0';
		fed = ft_strjoin(fed, temp);
		}
	}
	free(temp);
	return (fed);
}
/*
 * obtiene la siguiente linea de un archivo dado su descriptor fd
 * y almacenarla en una nueva cadena line
*/

char	*get_next_line(int fd)
{
	int				cont;
	char			*line;
	static char		*fed = NULL;

	cont = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fed || (fed && !ft_strchr(fed, '\n')))
		fed = ft_read(fd, fed);
	if (!fed)
		return (NULL);
	while (fed[cont] && fed[cont] != '\n')
		cont++;
	line = ft_substr(fed, 0, cont + 1);
	if (!line || !line[0])
	{
		free(line);
		return (true_free(&fed));
	}
	fed = ft_xtraspace(fed);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*str;
	fd = open("hola.txt", O_RDONLY);
	str = "aa";
	str = get_next_line(fd);
	printf("%s", str);
	close(fd);
	return (0);
}
*/
