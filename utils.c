/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:06:03 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/04 17:14:05 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
 * solo 5 funciones por archivo
*/
size_t	ft_strlen(const char *str)
{
	int		c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

/*
 * devuelve la subcadena de la cadena origen
 * que comienza en la posicion i
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str_new;
	size_t	len_s;
	size_t	cont;

	len_s = 0;
	while (s[len_s])
		len_s++;
	if (len_s < start)
		len = 0;
	else if (len >= (len_s - start))
		len = len_s - start;
	str_new = malloc(sizeof(char) * (len + 1));
	if (!str_new)
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		str_new[cont] = s[start];
		cont++;
		start++;
	}
	str_new[cont] = '\0';
	return (str_new);
}

/*
 * concatenacion de cadenas
*/
char	*ft_strjoin(char *s1, char *s2)
{
	int		cont_s1;
	int		cont_s2;
	char	*s3;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (true_free(&s1));
	cont_s1 = -1;
	cont_s2 = -1;
	while (s1[++cont_s1])
		s3[cont_s1] = s1[cont_s1];
	while (s2[++cont_s2])
		s3[cont_s1 + cont_s2] = s2[cont_s2];
	s3[cont_s1 + cont_s2] = '\0';
	free(s1);
	return (s3);
}
/**
 * @brief 
 * 
 * @param s 
 * @param c 
 * @return char* 
 */

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	if (s[cont] == (char)c)
		return ((char *)(s + cont));
	return (NULL);
}
/**
 * @brief 
 * 
 * @param s1 
 * @return char* 
 */

char	*ft_strdup(char *s1)
{
	char	*str_new;
	int		cont;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str_new = malloc(sizeof(char) * (len + 1));
	if (!str_new)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		str_new[cont] = s1[cont];
		cont++;
	}
	str_new[cont] = '\0';
	return (str_new);
}
