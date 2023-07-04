/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:32:16 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/29 20:18:51 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew_safe(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
	{
		free(content);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*current;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	node = ft_lstnew_safe((*f)(lst->content));
	if (!node)
		return (NULL);
	lst = lst->next;
	result = node;
	current = result;
	while (lst)
	{
		node = ft_lstnew_safe((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		current->next = node;
		current = current->next;
		lst = lst->next;
	}
	return (result);
}
