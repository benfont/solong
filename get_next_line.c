#include "so_long.h"

char	*true_free(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*ft_xtraspace(char *fed)
{
	int	i;
	int	j;
	char	*rest;

	i = 0;
	j = 0;
	while (fed[i] && fed[i] != '\n')
		i++;
	if (!fed[i])
	{
		free(fed);
		return (NULL);
	}
	if (fed[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(fed) - i + 1));
	if (!rest)
	{
		free(fed);
		return (NULL);
	}
	while (fed[i])
		rest[j++] = fed[i++];
	rest[j] = '\0';
	free(fed);
	return (rest);
}

char	*ft_read(int fd, char *fed)
{
	int	bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return(true_free(&fed));
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
		free(temp);
		return (fed);
	}
}

char	*get_next_line(int fd)
{
	int		cont;
	char		*line;
	static char	*fed = NULL;

	cont = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fed || (fed && !ft_strchr(fed, '\n')))
		fed = ft_read(fd, fed);
	if (!fed)
		return (NULL);
	while (fed[cont] && fed[cont] != '\n')
		cont++,
	line = ft_substr(fed, 0, cont + 1);
	if (!line || !line[0])
	{
		free(line);
		return (true_free(&fed));
	}
	fed = ft_xtraspace(fed);
	return (line);
}
