/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:30 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/27 20:06:52 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

//definicion de una estructura
//estructura -> colecciones de variables
//pueden contener diferentes tipos de datos

typedef struct s_game
{
	char	**map;
	char	*map_raw;
	int		width;
	int		height;
} t_game;

//check_errors functions.c
int				check_errors(int argc, char **argv);
//ft_split
//static int		word_counter(char const *s, char c);
//static void		memfree(char **str, size_t j);
//static char		**malloc_strings(char const *s, char c, char **words, size_t i);
char			**ft_split(char const *s, char c);
//get_next_line functions.c
char			*true_free(char **ptr);
char			*ft_xtraspace(char *fed);
char			*ft_read(int fd, char *fed);

//map
void			ft_read_map(char **argv, t_game *game);
char			*get_next_line(int fd);
void			ft_create_map(t_game *game);
void			ft_width(t_game *game);
void			ft_height(t_game *game);
//utils.c
size_t			ft_strlen(const char *str);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(char *s1);
//utils1.c
int				ft_strncmp(char *s1, char *s2, size_t n);
char			*ft_strnstr(const char *haystack, const char *needle, size_t len);
//check_barrier
int				ft_barrier_height(t_game *game);
int				ft_barrier_width(t_game *game);

#endif
