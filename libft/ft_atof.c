/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:31:29 by liafigli          #+#    #+#             */
/*   Updated: 2021/03/22 16:23:08 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int potenza(int a, int b)
{
    int i;

    i = 1;
    while (b--)
    {
        i *= a;
    }
    return (i);
}
// a e b vanno maalloccate con una funzione che conta i nums prima e dopo il punto
// le variabili possono essare messe in una struttura
float   ft_atof(char *s)
{
    char a[10];
    int i;
    int j;
    char b[10];

    i = 0;
    while (s[i] != '.')
    {
        a[i] = s[i];
        i++;
    }
    a[i] = '\0';
    i++;
    j = 0;
    while (s[j + i])
    {
        b[j] = s[j + i];
        j++;
    }
    b[j] = '\0';
    int x = ft_atoi(a);
    int y = ft_atoi(b);
    float z = (float)y / potenza(10,j);
    return (x + z);
}