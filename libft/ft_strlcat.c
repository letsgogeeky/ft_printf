/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:15:54 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/24 22:28:31 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(
	char *restrict dst,
	const char *restrict src,
	unsigned int dstsize
)
{
	unsigned int	dsize;
	unsigned int	ssize;
	unsigned int	current_index;

	dsize = ft_strlen(dst);
	ssize = ft_strlen(src);
	if (dstsize == 0)
	{
		return (ssize);
	}
	if (dstsize < dsize)
	{
		return (dstsize + ssize);
	}
	current_index = dsize;
	while (current_index < dstsize - 1 && *src != '\0')
	{
		dst[current_index] = *src;
		src++;
		current_index++;
	}
	dst[current_index] = '\0';
	return (ssize + dsize);
}
