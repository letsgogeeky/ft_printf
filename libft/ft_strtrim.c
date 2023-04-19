/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:18:24 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/26 19:03:36 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*trimmed;

	start = 0;
	if (!s1)
		return (0);
	end = ft_strlen(s1);
	trimmed = 0;
	if (s1 != 0 && set != 0)
	{
		while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
		while (start < end && ft_strchr(set, s1[start]))
			start++;
		trimmed = (char *)malloc(end - start + 1);
		if (trimmed)
		{
			ft_strlcpy(trimmed, &s1[start], end - start + 1);
		}	
	}
	return (trimmed);
}
