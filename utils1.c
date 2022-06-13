/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 02:48:29 by hkhalil           #+#    #+#             */
/*   Updated: 2022/06/13 02:49:08 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
