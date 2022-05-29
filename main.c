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

int main(int argc, char *argv[])
{
    t_data  img;
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
    img.mlx = mlx_init();
    m = n_columns(argv[1]);
    n = n_lines(argv[1]);
    img.mlx_win = mlx_new_window(img.mlx, m * 50, n * 50, "./so_long");
    img.img = mlx_new_image(img.mlx, m * 50, n * 50);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
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
            img.img = mlx_xpm_file_to_image(img.mlx, "xpm/background.xpm", &img.img_width, &img.img_height);
            mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, j, i);
            if (line[l] == '1')
            {
                img.img = mlx_xpm_file_to_image(img.mlx, "xpm/wall.xpm", &img.img_width, &img.img_height);
                mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, j, i);
            }
            else if (line[l] == 'C')
            {
                img.img = mlx_xpm_file_to_image(img.mlx, "xpm/coin.xpm", &img.img_width, &img.img_height);
                mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, j, i);
            }
            else if (line[l] == 'E')
            {
                img.img = mlx_xpm_file_to_image(img.mlx, "xpm/exit.xpm", &img.img_width, &img.img_height);
                mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, j, i);
            }
            else if (line[l] == 'P')
            {
                img.img = mlx_xpm_file_to_image(img.mlx, "xpm/position.xpm", &img.img_width, &img.img_height);
                mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, j, i);
            }
            l++;
            j += 50;
        }
        free(line);
        i += 50;
    }
    close(fd);
    mlx_loop(img.mlx);
    return (0);
}