/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:15:08 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/25 16:17:57 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void			*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == 0)
	{
		return (0);
	}
	ft_bzero(ptr, count * size);
	return (ptr);
}
