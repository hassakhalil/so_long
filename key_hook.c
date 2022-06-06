/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:30:35 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/30 03:30:52 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
    int x = 0;
    int y = 0;
    int nx = 0;
    int ny = 0;

    if (keycode == 53)
            exit(0);
    position(&x, &y, *game);
    if (keycode == 13)
    {
        ny = y - 1;
        nx = x;
    }
    else if (keycode == 0)
    {
        ny = y;
        nx = x - 1;
    }
    else if (keycode == 1)
    {
        ny = y + 1;
        nx = x;
    }
    else if (keycode == 2)
    {
        ny = y;
        nx = x + 1;
    }
    if (new_position(nx, ny, *game) == '1')
        return (0);
    else if (new_position(nx, ny, *game) == '0' || new_position(nx, ny, *game) == 'C')
    {
        printf("seg here\n");
        ((*game).map)[y][x] = '0';
        printf("seg here\n");
        ((*game).map)[ny][nx] = 'P';
        printf("seg here\n");
        map_draw(game);
    }
    else
    {
        printf("seg here\n");
        ((*game).map)[y][x] = '0';
        printf("seg here\n");
        map_draw(game);
        exit(0);
    }
	return (0);
}