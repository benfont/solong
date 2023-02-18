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

char	*ft_strjoin(char *s1, char *s2)
{
	int	cont_s1;
	int	cont_s2;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	cont_s1 = 0;
	cont_s2 = 0;
	while (s1[cont_s1])
	{
		s3[cont_s1] = s1[cont_s1];
		cont_s1++;
	}
	free(s1);
	while (s2[cont_s2])
	{
		s3[cont_s1 + cont_s2] = s2[cont_s2];
		cont_s2++;
	}
	s3[cont_s1 + cont_s2] = '\0';
	free(s2);
	return (s3);
}

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}
