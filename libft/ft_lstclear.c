/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:55:57 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/29 20:21:27 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*to_free;

	if (!(*lst))
		return ;
	current = *lst;
	while (current && current->next)
	{
		to_free = current;
		current = current->next;
		del(to_free->content);
		free(to_free);
	}
	if (current)
	{
		del(current->content);
		free(current);
	}
	*lst = NULL;
}
