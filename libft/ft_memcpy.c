/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:47:02 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/22 15:54:09 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*sstr;

	i = 0;
	str = (unsigned char *)dst;
	sstr = (unsigned char *)src;
	if (str == NULL && sstr == NULL)
	{
		return (dst);
	}
	while (i < n)
	{
		str[i] = sstr[i];
		i++;
	}
	return (dst);
}
