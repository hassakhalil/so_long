/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:10:19 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/12 04:33:52 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	n_columns(char *s)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(s, O_RDWR);
	i = 0;
	line = get_next_line(fd);
	if (!line)
		return (0);
	i = ft_strlen(line) - 1;
	free(line);
	return (i);
}

int	n_lines(char *s)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(s, O_RDWR);
	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 0;
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (i);
}

int	find_position(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	position(int *x, int *y, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (((*game).map)[i])
	{
		if (find_position(((*game).map)[i], 'P'))
		{
			j = 0;
			while (((*game).map)[i][j] != 'P')
				j++;
			*y = i;
			*x = j;
			return ;
		}
		(*y)++;
		i++;
	}
}

void	convert_map(t_data *game)
{
	int	fd;
	int	i;

	fd = open((*game).file_name, O_RDWR);
	i = 0;
	(*game).map = malloc(sizeof(char *) * ((*game).n + 1));
	while (i < (*game).n)
	{
		((*game).map)[i] = get_next_line(fd);
		i++;
	}
	((*game).map)[i] = NULL;
	close(fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	x;

	x = n;
	if (x < 0)
	{
		write(fd, "-", 1);
		x = x * (-1);
	}
	if (x > 9)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
	{
		c = x + '0';
		write(fd, &c, 1);
	}
}

int	number_of_collectibles(t_data *game)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (((*game).map)[i])
	{
		j = 0;
		while (((*game).map)[i][j])
		{
			if (((*game).map)[i][j] == 'C')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

void	free_game(t_data *game)
{
	int	i;

	i = 0;
	free((*game).file_name);
	free((*game).img);
	free((*game).addr);
	free((*game).mlx);
	free((*game).mlx_win);
	while (((*game).map)[i])
	{
		free(((*game).map)[i]);
		i++;
	}
	free(((*game).map)[i]);
	free((*game).map);
	free(game);
}
