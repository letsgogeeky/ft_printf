/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/22 11:48:26 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	unsigned char	cr;

	cr = (unsigned char) c;
	ptr = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == cr)
		{
			ptr = (char *)s;
		}
		s++;
	}
	if (cr == '\0' && *s == '\0')
	{
		return ((char *)s);
	}
	return (ptr);
}
