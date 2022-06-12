/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:52:24 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/12 03:54:39 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
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

int	check_min_req(char *s)
{
	int		position;
	int		collectibles;
	int		exit;
	int		fd;
	char	*line;

	position = 0;
	collectibles = 0;
	exit = 0;
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strchr(line, 'E'))
			exit++;
		if (ft_strchr(line, 'C'))
			collectibles++;
		if (ft_strchr(line, 'P'))
			position++;
		free(line);
		line = get_next_line(fd);
	}
	if (position != 1 || !collectibles || exit != 1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	check_for_errors(char *s)
{
	size_t	n;
	int		fd;
	char	*line;
	char	*last;

	n = ft_strlen(s);
	if (s[n - 4] != '.' || s[n - 3] != 'b'
		|| s[n - 2] != 'e' || s[n - 1] != 'r')
		return (-1);
	fd = open(s, O_RDWR);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	n = ft_strlen(line);
	if (check_first_last_line(line))
	{
		close(fd);
		free(line);
		return (-1);
	}
	free(line);
	line = get_next_line(fd);
	last = ft_strdup(line);
	while (line)
	{
		free(last);
		last = ft_strdup(line);
		if (check_line(line) || ft_strlen(line) != n)
		{
			close(fd);
			free(line);
			free(last);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_first_last_line(last))
	{
		close(fd);
		free(last);
		return (-1);
	}
	close(fd);
	free(last);
	if (check_min_req(s))
		return (-1);
	return (0);
}
