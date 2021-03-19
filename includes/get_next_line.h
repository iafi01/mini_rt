/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 10:29:57 by rchallie          #+#    #+#             */
/*   Updated: 2021/03/16 15:09:13 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

int					get_next_line(int fd, char **line);
int					checkln(char *str);
size_t			    ft_strlen(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
void		        *ft_memmove(void *dst, const void *src, size_t len);

#endif