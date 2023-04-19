/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:56:00 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/26 16:26:34 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	ft_forwardcpy(void *dst, const void *src, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, unsigned int len)
{
	unsigned char	*src_ptr;
	unsigned char	*dst_ptr;

	src_ptr = (unsigned char *)src;
	dst_ptr = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (dst);
	if (src_ptr >= dst_ptr || dst_ptr >= (src_ptr + len))
	{
		ft_forwardcpy(dst, src, len);
	}
	else
	{
		dst_ptr += len - 1;
		src_ptr += len - 1;
		while (len > 0)
		{
			*dst_ptr-- = *src_ptr--;
			len--;
		}
	}
	return (dst);
}
