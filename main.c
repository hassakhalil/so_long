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
    void    *mlx;
    void    *mlx_win;
    char	*relative_path;
    t_data  img;
	int		img_width;
	int		img_height;
    int     n = 0;
    int     m = 0;
    int     i = 0;
    int     j = 0;

    if (argc != 2 || check_for_errors(argv[1]))
    {
        write(2, "Error\n", 7);
        return (-1); 
    }
    mlx = mlx_init();
    m = n_columns(argv[1]);
    n = n_lines(argv[1]);
    mlx_win = mlx_new_window(mlx, m * 50, n * 50, "./so_long");
    img.img = mlx_new_image(mlx, m * 50, n * 50);
    relative_path = "xpm/white-_1_.xpm";
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    while(i < n * 50)
    {
        j = 0;
        while (j < m * 50)
        {
            mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);
            j += 50;
        }
        i += 50;
    }
    relative_path = "xpm/coin.xpm";
    img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    i = 0;
    while(i < n * 50)
    {
        j = 0;
        while (j < m * 50)
        {
            mlx_put_image_to_window(mlx, mlx_win, img.img, j, i);
            j += 50;
        }
        i += 50;
    }
    mlx_loop(mlx);
    return (0);
}