/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/21 17:31:12 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_errors(int argc, char **argv)
{
	if (argc != 2)
	{
		write (2, "Error\nBad arg number", 20);
		exit(-1);
	}
	if (open(argv[1], O_RDONLY) == 0)
	{
		write(2, "Error\nEmpty file", 16);
		exit(-1);
	}
	if (open (argv[1], O_RDONLY) == -1)
	{
		write(2, "Error\nNo read file", 18);
		exit(-1);
	}
	if (ft_strncmp (argv[1], ".ber") == -1)
	{
		write(2, "Error\nWrong file name", 2);
		exit(-1);
	}
	return (0);
}

