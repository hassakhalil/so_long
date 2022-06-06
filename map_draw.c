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

void  map_draw(t_data *game)
{
    int     i;
    int     j;
    int     l;
    int     k;

    i = 0;
    k = 0;
    while(k < (*game).n)
    {
        j = 0;
        l = 0;
        while (l < (*game).m)
        {
            (*game).img = mlx_xpm_file_to_image((*game).mlx, "xpm/background.xpm", &(*game).img_width, &(*game).img_height);
            mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img, j, i);
            if ((*game).map[k][l] == '1')
            {
                (*game).img = mlx_xpm_file_to_image((*game).mlx, "xpm/wall.xpm", &(*game).img_width, &(*game).img_height);
                mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img, j, i);
            }
            else if ((*game).map[k][l] == 'C')
            {
                (*game).img = mlx_xpm_file_to_image((*game).mlx, "xpm/coin.xpm", &(*game).img_width, &(*game).img_height);
                mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img, j, i);
            }
            else if ((*game).map[k][l] == 'E')
            {
                (*game).img = mlx_xpm_file_to_image((*game).mlx, "xpm/exit.xpm", &(*game).img_width, &(*game).img_height);
                mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img, j, i);
            }
            else if ((*game).map[k][l] == 'P')
            {
                (*game).img = mlx_xpm_file_to_image((*game).mlx, "xpm/position.xpm", &(*game).img_width, &(*game).img_height);
                mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img, j, i);
            }
            l++;
            j += 50;
        }
        i += 50;
        k++;
    }
}