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

int find_position(char *s, int c)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

void    position(int *x, int *y, t_data *game)
{
    int i = 0;
    int j = 0;

    printf("before the seg\n");
    printf("%s\n", ((*game).map)[0]);
    while (((*game).map)[i])
    {
        if (find_position(((*game).map)[i], 'P'))
        {
            printf("made it here!\n");
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
    ((*game).map)[i] = NULL;
    close(fd);
}
