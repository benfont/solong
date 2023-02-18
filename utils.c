/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:06:03 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/18 14:51:55 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 * solo 5 funciones por archivo
*/
int	ft_strncmp(char *s1, char *s2, char start, size_t n)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (0);
	while (s1[i] != start)
		i++;
	while (s2[cont] != start)
		cont++;
	while (s1[i] == s2[cont] && s1[i] && s2[cont] && (i < n - 1))
	{
		i++;
		cont++;
	}
	return ((unsigned char)s1[i] - (unsigned char) s2[count]);
}

char	*ft_strjoin(char *line, int fd, )
{
	
}
