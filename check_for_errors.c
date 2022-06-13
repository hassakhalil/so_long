/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:52:24 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/13 02:46:24 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(char *wall)
{
	int	i;

	i = 0;
	while (wall[i] != '\n')
	{
		if (wall[i] != '1')
			return (-1);
		i++;
	}
	free(wall);
	return (0);
}

int	check_first_last_line(char *s)
{
	char	*line;
	char	*last;
	char	*first;
	int		fd;
	int		n;

	fd = open(s, O_RDWR);
	first = get_next_line(fd);
	n = ft_strlen(first);
	line = get_next_line(fd);
	last = ft_strdup(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			free(last);
			last = ft_strdup(line);
		}
	}
	close(fd);
	if (check_walls(first) == -1 || check_walls(last) == -1)
		return (-1);
	return (n);
}

int	check_line(char *line)
{
	int		i;
	char	c;

	i = 0;
	if (line[i] != '1')
		return (-1);
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1'
			&& line[i] != 'C' && line[i] != 'E' && line[i] != 'P')
			return (-1);
		c = line[i];
		i++;
	}
	if (line[i -1] != '1')
		return (-1);
	return (0);
}

void	check_min_req_h(char *s, int *position, int *collectibles, int *exit)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(s, O_RDWR);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == 'E')
				(*exit)++;
			if (line[i] == 'C')
				(*collectibles)++;
			if (line[i] == 'P')
				(*position)++;
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
}

int	check_min_req(char *s)
{
	int		position;
	int		collectibles;
	int		exit;

	position = 0;
	collectibles = 0;
	exit = 0;
	check_min_req_h(s, &position, &collectibles, &exit);
	if (position != 1 || !collectibles || !exit)
		return (-1);
	return (0);
}

int	check_mid_lines(char *s, int n)
{
	int		fd;
	char	*line;

	fd = open(s, O_RDWR);
	line = get_next_line(fd);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (check_line(line) || ft_strlen(line) != (size_t)n)
		{
			close(fd);
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	check_for_errors(char *s)
{
	int	n;

	n = ft_strlen(s);
	if (s[n - 4] != '.' || s[n - 3] != 'b'
		|| s[n - 2] != 'e' || s[n - 1] != 'r')
		return (-1);
	n = check_first_last_line(s);
	if (n == -1 || check_mid_lines(s, n) == -1)
		return (-1);
	if (check_min_req(s))
		return (-1);
	return (0);
}
