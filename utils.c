/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:10:19 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/23 22:10:33 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int n_columns(char *s)
{
    int     fd;
    int     i;
    char    *line;

    fd = open(s, O_RDWR);
    i = 0;
    line = get_next_line(fd);
    if (!line)
        return (0);
    i = ft_strlen(line) - 1;
    free(line);
    return (i);
}

int n_lines(char *s)
{
    int     fd;
    int     i;
    char    *line;

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