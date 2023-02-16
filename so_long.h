/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:30 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/16 14:32:43 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

/* definicion de una estructura
 * estructura -> colecciones de variables
 * pueden contener diferentes tipos de datos
*/
typedef struct s_game
{
	char	**map;
	char	*map_raw;
	int		width;
	int		height;
} t_game;
