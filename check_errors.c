/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:36 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/15 21:10:05 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_errors(int argc)
{
	if (argc != 2)
	{
		write (2, "Error\nBad arg number", 20);
		exit (-1);
	}
	if (argv[0], O_RDONLY)
	{
		write(2, "Error\nNo read no file", 21);
		exit (-1);
	}
	if (argv[0], O_WRONLY)
	{
		write(2, "Error\nEmpty file", 16);
		exit (-1);
	}
	if (argv[0], )
	{
		write(2, "Error\nWrong file name", 21 );
		exit (-1);
	}
}

