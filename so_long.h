/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:30 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/18 14:34:42 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

/*
 * check_errors functions.c
*/
int		check_errors(int argc, char **argv);

/*
 * get_next_line functions.c
*/
char	*true_free(char **ptr);
char	*ft_xtraspace(char *fed);
char	*ft_read(int fd, char *fed);
char	*get_next_line(int fd);

/*
 * utils.c
*/
size_t		ft_strlen(const char *str);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(char *line, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
/*
* utils1.c
*/
int		ft_strncmp(char *s1, char *s2, char start, size_t n);

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
