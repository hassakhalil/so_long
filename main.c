/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:20:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/12 03:58:03 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_data *game)
{
	free_game(game);
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_data	*game;

	if (argc != 2 || check_for_errors(argv[1]))
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	game = malloc(sizeof(t_data));
	(*game).file_name = ft_strdup(argv[1]);
	(*game).mlx = mlx_init();
	(*game).m = n_columns((*game).file_name);
	(*game).n = n_lines((*game).file_name);
	convert_map(game);
	(*game).mlx_win = mlx_new_window((*game).mlx,
			(*game).m * 50, (*game).n * 50, "./so_long");
	(*game).img = mlx_new_image((*game).mlx, (*game).m * 50, (*game).n * 50);
	(*game).addr = mlx_get_data_addr((*game).img,
			&(*game).bits_per_pixel, &(*game).line_length, &(*game).endian);
	map_draw(game);
	mlx_key_hook((*game).mlx_win, key_hook, game);
	mlx_hook((*game).mlx_win, 17, 0, ft_close, game);
	mlx_loop((*game).mlx);
	return (0);
}
