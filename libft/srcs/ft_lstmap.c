/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liafigli <liafigli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:09:58 by liafigli          #+#    #+#             */
/*   Updated: 2021/04/07 10:39:12 by liafigli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list *tmp;
	t_list *i;

	if (!lst)
		return (0);
	tmp = NULL;
	while (lst)
	{
		if (!(i = ft_lstnew((f)(lst->content))))
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, i);
		lst = lst->next;
		i = i->next;
	}
	return (tmp);
}
