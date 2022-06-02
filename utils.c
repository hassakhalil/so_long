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

void    position(int *x, int *y, t_data game)
{
    int     fd;
    char    *line;

    fd = open(game.map, O_RDWR);
    line = get_next_line(fd);
    while (line)
    {
        if (ft_strchr(line, 'P'))
        {
            *x = 0;
            while (line[*x] != 'P')
                (*x)++;
            free(line);
            close(fd);
            return ;
        }
        free(line);
        line = get_next_line(fd);
        (*y)++;
    }
}

int		new_position(int nx, int ny, t_data game)
{
    int     fd;
    int     i;
    int     c;
    char    *line;

    fd = open(game.map, O_RDWR);
    i = 0;
    line  = get_next_line(fd);
    while (i != ny)
    {
        free(line);
        line  = get_next_line(fd);
        i++;
    }
    c = line[nx];
    free(line);
    return (c);
}