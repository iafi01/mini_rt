/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:27:54 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/07 14:40:31 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

void    ft_printf(char *color, char *str)
{
    printf("%s",color);
    printf("%s",str);
    printf("%c",'\n');
    printf(RESET);
}