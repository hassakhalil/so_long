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
	close(fd);
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
	close(fd);
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

void	position(t_data *game)
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
			(*game).y = i;
			(*game).x = j;
			return ;
		}
		((*game).y)++;
		i++;
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
