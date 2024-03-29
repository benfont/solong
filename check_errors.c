/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/04/08 22:40:59 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//verifica los argumentos recibidos
int	check_errors(int argc, char **argv)
{
	int		fd;
	size_t	len;

	len = 0;
	(void) argv;
	if (argc != 2)
	{
		write (2, "Error\nBad arg number\n", 20);
		exit(-1);
	}
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		exit(-1);
	}
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".ber", 4))
	{
		write (2, "Error\nIncorrect extension\n", 25);
		exit(-1);
	}
	close(fd);
	return (0);
}
