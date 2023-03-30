/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:11:30 by aitlopez          #+#    #+#             */
/*   Updated: 2023/03/30 16:50:20 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 32

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "mlx/mlx.h"

//definicion de una estructura
//estructura -> colecciones de variables
//pueden contener diferentes tipos de datos

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	*map_raw;
	char	**cp_map;
	char	**cp_map2;
	int		width;
	int		height;
	t_img	*imgs;
	int		keycode;
	int		player;
	int		collect;
	int		exit;
	int		position;
	int		player_x;
	int		player_y;
	int		contador;
	int		collect_cp;
	int		fuera;
}	t_game;

//check_errors functions.c
int		check_errors(int argc, char **argv);
int		check_rectangular_map(t_game *game);
int		content_map(t_game *game);
//ft_split
char	**ft_split(char const *s, char c);
//get_next_line functions.c
char	*true_free(char **ptr);
char	*ft_xtraspace(char *fed);
char	*ft_read(int fd, char *fed);
//map
void	read_map(char **argv, t_game *game);
char	*get_next_line(int fd);
void	create_map(t_game *game);
void	width(t_game *game);
void	height(t_game *game);
//utils.c
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
//utils1.c
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//check_barrier
int		barrier_width(t_game *game);
int		barrier_height(t_game *game);
//check_rectangle
void	check_len_width(t_game *game);
void	check_len_height(t_game *game);
//check_characters
int		check_characters(t_game *game);
//upload_images
void	upload_images(t_game *game);
//print_map
void	print_map(t_game *game);
//ft_print_characters
void	print_barrier(t_game *game, int col, int fil);
void	print_espacio(t_game *game, int col, int fil);
void	print_coleccionable(t_game *game, int col, int fil);
void	print_exit(t_game *game, int col, int fil);
void	print_heroe_w(t_game *game, int col, int fil);
//ft_movements
int		movements(int keycode, t_game *game);
int		free_exit(t_game *game);
//can_move
int		can_move_w_s(t_game *game);
int		can_move_a_d(t_game *game);
//check_items
int		check_items(t_game *game);
void	check_items_error(t_game *game);
void	get_pos_player(t_game *game);
int		can_exit(t_game *game);
//free_map
void	free_map(t_game *game);
//ft_contador
int		ft_contador(int cont, t_game *game);
//ft_itoa
int		ft_cifras(long nb);
char	*mayomen(char *s, int cifras, long m);
char	*ft_itoa(int n);
//ft_putchar
char	ft_putchar(char c);
char	ft_putnbr(int nb);
//exit_game
int		can_exit(t_game *game);
void	you_win(t_game *game);
int		ft_free_exit(t_game *game);
//ft_check_path
char	**copy_map(t_game *game);
int		check_path(t_game *game, int col, int fil);
int		check_exit(t_game *game, int col, int fil);
//error_message
void	error_message(void);
void	no_read_file(void);
void	no_map(void);
//ft_save_parameters
//void			save_parameters(t_game *game);

#endif
