/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:30:35 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/12 04:53:38 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *game)
{
	int			x;
	int			y;
	int			nx = 0;
	int			ny = 0;
	static int	moves = 0;
	static int	collectibles = 0;

	if (keycode == 53)
	{
		free_game(game);
		exit(0);
	}
	if (!collectibles)
		collectibles = number_of_collectibles(game);
	position(&x, &y, game);
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
	if (((*game).map)[ny][nx] == '1')
		return (0);
	if (((*game).map)[ny][nx] == '0' || ((*game).map)[ny][nx] == 'C')
	{
		ft_putnbr_fd(++moves, 1);
		write(1, "\n", 1);
		if (((*game).map)[ny][nx] == 'C')
			collectibles--;
		((*game).map)[y][x] = '0';
		((*game).map)[ny][nx] = 'P';
		map_draw(game);
	}
	else
	{
		if (collectibles)
			return (0);
		ft_putnbr_fd(++moves, 1);
		write(1, "\n", 1);
		((*game).map)[y][x] = '0';
		map_draw(game);
		free_game(game);
		exit(0);
	}
	return (0);
}
