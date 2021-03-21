/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 12:40:18 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/21 12:58:28 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

int check_type(char *line)
{
    if (line[0] == 'R')
        parse_resolution(line);
    if (line[0] == 'A')
        parse_ambient(line);
        //....ecccccc....
}

int parse(char *path, int bmp)
{
    int fd;
    char **line;

    if (fd = open(path, O_RDONLY) < 0)
        ft_putstr("Error can't open the scene rt file");
    while (get_next_line(fd, line) > 0)
    {
        if (check_type(*line))
            ft_putstr("File rt has an error first char");
    }
    close(fd);
    return (0);
}

int parse_resolution(char *line)
{
    
}