/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:56:16 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/25 16:24:46 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		s1_size;
	char	*s2;
	int		idx;

	s1_size = ft_strlen(s1);
	s2 = (char *)malloc(s1_size + 1);
	if (s2 == 0)
	{
		return (0);
	}
	idx = 0;
	while (idx < s1_size)
	{
		s2[idx] = s1[idx];
		idx++;
	}
	s2[idx] = '\0';
	return (s2);
}
