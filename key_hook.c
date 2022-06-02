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

    if (keycode == 53)
            exit(0);
     //get the position of P
    //check next position
        //if up = '1' -> do nothing
        //if up = '0' || up = 'C' -> change the map & draw new map
        // if up = 'E' change the map & exit
    position(&x, &y, *game);
    printf("x = %d and y = %d\n", x, y);
    /*else if (keycode == 13)
    {
        //up
        printf("W\n");
    }
    else if (keycode == 0)
    {
        //left
        printf("A\n");
    }
    else if (keycode == 1)
    {
        //down
        printf("S\n");
    }
    else if (keycode == 2)
    {
        //right
        printf("D\n");
    }*/
	return (0);
}