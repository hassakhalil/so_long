/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:29:33 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/12 04:15:29 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_data *game, char *s, int i, int j)
{
	(*game).img = mlx_xpm_file_to_image((*game).mlx,
			s, &(*game).img_width, &(*game).img_height);
	mlx_put_image_to_window((*game).mlx, (*game).mlx_win, (*game).img, j, i);
}

void	map_draw(t_data *game)
{
	int	l;
	int	k;

	k = 0;
	while (k < ((*game).n))
	{
		l = 0;
		while (l < (*game).m)
		{
			draw(game, "xpm/background.xpm", k * 50, l * 50);
			if ((*game).map[k][l] == '1')
				draw(game, "xpm/wall.xpm", k * 50, l * 50);
			else if ((*game).map[k][l] == 'C')
				draw(game, "xpm/coin.xpm", k * 50, l * 50);
			else if ((*game).map[k][l] == 'E')
				draw(game, "xpm/exit.xpm", k * 50, l * 50);
			else if ((*game).map[k][l] == 'P')
				draw(game, "xpm/position.xpm", k * 50, l * 50);
			l++;
		}
		k++;
	}
}
