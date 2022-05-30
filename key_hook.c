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

int	key_hook(int keycode)
{
    printf("%d\n", keycode);
    if (keycode == 53)
            exit(0);
    else if (keycode == 13)
    {
        printf("W\n");
    }
    else if (keycode == 0)
    {
        printf("A\n");
    }
    else if (keycode == 1)
    {
        printf("S\n");
    }
    else if (keycode == 2)
    {
        printf("D\n");
    }
	return (0);
}