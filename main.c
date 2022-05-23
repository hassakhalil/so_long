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
    void    *img;


    if (argc != 2 || check_for_errors(argv[1]))
    {
        write(2, "Error\n", 7);
        return (-1); 
    }
    mlx = mlx_init();
    img = mlx_new_image(mlx, 1920, 1080);
    mlx_win = mlx_new_window(mlx, 1920, 1080, "game");
    //mlx_loop(mlx);
    return (0);
}