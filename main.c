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
    t_data  game;
    int     n = 0;
    int     m = 0;

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
    mlx_key_hook(map_draw(n, m, game, argv[1]).mlx_win, key_hook, &game);
    mlx_loop(map_draw(n, m, game, argv[1]).mlx);
    return (0);
}