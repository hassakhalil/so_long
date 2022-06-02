/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:29:33 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/01 22:29:37 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data  map_draw(int n, int m, t_data game)
{
    int     fd;
    int     i;
    int     j;
    int     l;
    char    *line;

    fd = open(game.map, O_RDWR);
    i = 0;
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
        i += 50;
    }
    close(fd);
    return (game);
}