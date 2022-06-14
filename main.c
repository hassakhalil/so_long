/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:20:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/12 03:59:33 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	x;

	x = n;
	if (x < 0)
	{
		write(fd, "-", 1);
		x = x * (-1);
	}
	if (x > 9)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
	{
		c = x + '0';
		write(fd, &c, 1);
	}
}

void	convert_map(t_data *game)
{
	int	fd;
	int	i;

	fd = open((*game).file_name, O_RDWR);
	i = 0;
	(*game).map = malloc(sizeof(char *) * ((*game).n + 1));
	while (i < (*game).n)
	{
		((*game).map)[i] = get_next_line(fd);
		printf("%s", ((*game).map)[i]);
		i++;
	}
	((*game).map)[i] = NULL;
	close(fd);
}

void	free_game(t_data *game)
{
	int	i;

	i = 0;
	free((*game).file_name);
	free((*game).img);
	free((*game).addr);
	free((*game).mlx);
	free((*game).mlx_win);
	while (((*game).map)[i])
	{
		free(((*game).map)[i]);
		i++;
	}
	free(((*game).map)[i]);
	free((*game).map);
	free(game);
}

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
	(*game).n = n_lines((*game).file_name);
	convert_map(game);
	(*game).m = n_columns((*game).file_name);
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
