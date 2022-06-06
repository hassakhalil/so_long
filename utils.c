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
    *y = 0;
    while (*y < game.n)
    {
        if (ft_strchr((game.map)[*y], 'P'))
        {
            *x = 0;
            while ((game.map)[*y][*x] != 'P')
                (*x)++;
            return ;
        }
        (*y)++;
    }
}


void    convert_map(t_data *game)
{
    int     fd;
    int     i;

    fd = open((*game).file_name, O_RDWR);
    i = 0;
    (*game).map = malloc(sizeof(char *) * ((*game).n + 1));
    while(i < (*game).n)
    {
        ((*game).map)[i]  = get_next_line(fd);
        i++;
    }
    ((*game).map)[i] = malloc(sizeof(char *));
    ((*game).map)[i] = NULL;
    close(fd);
}