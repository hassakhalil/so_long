/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhalil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:52:24 by hkhalil           #+#    #+#             */
/*   Updated: 2022/05/20 11:52:46 by hkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_for_errors(int argc, char *s)
{
     //check if the map is a .ber file and its valid
     int  n;
     int  fd;
     char *line;
     char *last;

     n = ft_strlen(s);
     if (s[n - 1] != '.' || s[n - 3] != 'b'  || s[n - 2] != 'e' || s[n - 1] != 'r')
          return (-1);
     fd = open(s, O_RDWR);
     line = get_next_line(fd);
     n = ft_strlen(line);
     if(check_first_last_line(line))
          return (-1);
     line = get_next_line(fd);
     while(line)
     {
          last = ft_strdup(line);
          if (check_line(line) || ft_strlen(line) != n)
               return (-1);
          line = get_next_line(fd);
     }
     if(check_first_last_line(last))
          return (-1);
     if (check_min_req(fd))
          return(-1);

     11111111
     10000001
     10000001
     10010001
     10011001
     11111111
     //and check for all errors
     close(fd);
     return (0);
}