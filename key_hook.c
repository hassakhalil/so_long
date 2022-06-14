/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 03:30:35 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/13 01:25:32 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_position(t_data *game, int keycode)
{
	if (keycode == 13)
	{
		((*game).ny) = ((*game).y) - 1;
		((*game).nx) = (*game).x;
	}
	else if (keycode == 0)
	{
		((*game).ny) = (*game).y;
		((*game).nx) = (*game).x - 1;
	}
	else if (keycode == 1)
	{
		((*game).ny) = ((*game).y) + 1;
		((*game).nx) = (*game).x;
	}
	else if (keycode == 2)
	{
		((*game).ny) = ((*game).y);
		((*game).nx) = ((*game).x) + 1;
	}
	else
		((*game).ny) = ((*game).y);
		((*game).nx) = ((*game).x);
}

void	free_exit(t_data *game)
{
	free_game(game);
	exit(0);
}

void	last_move(t_data *game, int collectibles, int *moves)
{
	if (collectibles)
		return ;
	ft_putnbr_fd(++(*moves), 1);
	write(1, "\n", 1);
	((*game).map)[((*game).y)][((*game).x)] = '0';
	map_draw(game);
	free_exit(game);
}

int	key_hook(int keycode, t_data *game)
{
	static int	moves = 0;
	static int	collectibles = 0;

	if (keycode == 53)
		free_exit(game);
	if (!collectibles)
		collectibles = number_of_collectibles(game);
	position(game);
	new_position(game, keycode);
	if (((*game).map)[((*game).ny)][((*game).nx)] == '1')
		return (0);
	if (((*game).map)[((*game).ny)][((*game).nx)] == '0'
		|| ((*game).map)[((*game).ny)][((*game).nx)] == 'C')
	{
		ft_putnbr_fd(++moves, 1);
		write(1, "\n", 1);
		if (((*game).map)[((*game).ny)][((*game).nx)] == 'C')
			collectibles--;
		((*game).map)[((*game).y)][((*game).x)] = '0';
		((*game).map)[((*game).ny)][((*game).nx)] = 'P';
		map_draw(game);
	}
	else
		last_move(game, collectibles, &moves);
	return (0);
}
