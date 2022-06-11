/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:21:41 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/20 11:21:49 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void    *mlx_win;
	int		img_width;
	int		img_height;
	char	**map;
	char	*file_name;
	int		n;
	int		m;
}				t_data;
int		check_for_errors(char *s);
int 	n_columns(char *s);
int 	n_lines(char *s);
int		key_hook(int keycode, t_data *game);
void	map_draw(t_data *game);
void    position(int *x, int *y, t_data *game);
void    convert_map(t_data *game);
void	ft_putnbr_fd(int n, int fd);
int number_of_collectibles(t_data *game);
void    free_game(t_data *game);
#endif
