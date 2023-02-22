/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:22:02 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/22 11:30:35 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * compara n caracteres de 2 strings
*/
int	ft_strncmp(char *s1, char *s2, char start, size_t n)
{
	size_t	i;
	int		cont;

	i = 0;
	cont = 0;
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
	return ((unsigned char) s1[i] - (unsigned char) s2[count]);
}
