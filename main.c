/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:20:45 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/20 11:21:14 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode)
{
    (void)keycode;
	printf("Hello from key_hook!\n");
	return (0);
}

int main(int argc, char *argv[])
{
    t_data  game;
    int     n = 0;
    int     m = 0;
    int     i = 0;
    int     j = 0;
    int     l;
    char    *line;
    int     fd;

    if (argc != 2 || check_for_errors(argv[1]))
    {
        write(2, "Error\n", 7);
        return (-1); 
    }
    game.mlx = mlx_init();
    m = n_columns(argv[1]);
    n = n_lines(argv[1]);
    game.mlx_win = mlx_new_window(game.mlx, m * 50, n * 50, "./so_long");
    game.img = mlx_new_image(game.mlx, m * 50, n * 50);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
    fd = open(argv[1], O_RDWR);
    if (fd == -1)
        return (-1);
    while(i < n * 50)
    {
        j = 0;
        l = 0;
        line = get_next_line(fd);
        while (j < m * 50)
        {
            game.img = mlx_xpm_file_to_image(game.mlx, "xpm/background.xpm", &game.img_width, &game.img_height);
            mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, j, i);
            if (line[l] == '1')
            {
                game.img = mlx_xpm_file_to_image(game.mlx, "xpm/wall.xpm", &game.img_width, &game.img_height);
                mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, j, i);
            }
            else if (line[l] == 'C')
            {
                game.img = mlx_xpm_file_to_image(game.mlx, "xpm/coin.xpm", &game.img_width, &game.img_height);
                mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, j, i);
            }
            else if (line[l] == 'E')
            {
                game.img = mlx_xpm_file_to_image(game.mlx, "xpm/exit.xpm", &game.img_width, &game.img_height);
                mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, j, i);
            }
            else if (line[l] == 'P')
            {
                game.img = mlx_xpm_file_to_image(game.mlx, "xpm/position.xpm", &game.img_width, &game.img_height);
                mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, j, i);
            }
            l++;
            j += 50;
        }
        free(line);
        mlx_key_hook(game.mlx_win, key_hook, &game);
        i += 50;
    }
    close(fd);
    mlx_loop(game.mlx);
    return (0);
}