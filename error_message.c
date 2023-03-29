/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:50:24 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/29 18:35:12 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(void)
{
	write (2, "Error\nMapa incorrecto\n", 23);
	exit(-1);
}

void	no_read_file(void)
{
	write(1, "Error\nNo read file\n", 19);
	exit(-1);
}

void	no_map(void)
{
	write(1, "Error\nNo map\n", 14);
	exit(-1);
}
