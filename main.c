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
    t_data  *game = malloc(sizeof(t_data));

    if (argc != 2 || check_for_errors(argv[1]))
    {
        write(2, "Error\n", 7);
        return (-1);
    }
    (*game).file_name = ft_strdup(argv[1]);
    convert_map(*game);
    (*game).mlx = mlx_init();
    (*game).m = n_columns((*game).file_name);
    (*game).n = n_lines((*game).file_name);
    (*game).mlx_win = mlx_new_window((*game).mlx, (*game).m * 50, (*game).n * 50, "./so_long");
    (*game).img = mlx_new_image((*game).mlx, (*game).m * 50, (*game).n * 50);
    (*game).addr = mlx_get_data_addr((*game).img, &(*game).bits_per_pixel, &(*game).line_length, &(*game).endian);
    map_draw(game);
    mlx_key_hook((*game).mlx_win, key_hook, &game);
    mlx_loop((*game).mlx);
    return (0);
}