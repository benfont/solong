/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/16 14:31:50 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_errors(int argc)
{
	if (argc != 2)
	{
		write (2, "Error\nBad arg number", 20);
		exit (-1);
	}
	if (read (argv[1], O_RDONLY) == -1)
	{
		write(2, "Error\nNo read file", 18);
		exit (-1);
	}
	if (write (argv[1], O_WRONLY) == -1)
	{
		write(2, "Error\nEmpty file", 16);
		exit (-1);
	}
	if (read (argv[1], O_RDONLY) == -1)
	{
		write(2, "Error\nWrong file name", 21 );
		exit (-1);
	}
}

