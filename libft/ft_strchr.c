/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:21:56 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/22 11:09:28 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cr;

	cr = (unsigned char)c;
	while (*s != '\0')
	{
		if ((unsigned char)*s == cr)
		{
			return ((char *)s);
		}
		s++;
	}
	if (cr == '\0' && *s == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}
