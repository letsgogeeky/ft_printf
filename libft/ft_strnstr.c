/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:47:35 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/27 11:42:42 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int len)
{
	unsigned int	start;
	unsigned int	current;
	unsigned int	needle_len;

	start = 0;
	current = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
	{
		return ((char *)haystack);
	}
	while (haystack[start] != '\0' && start + needle_len <= len)
	{
		current = 0;
		while (current < needle_len
			&& needle[current] == haystack[current + start])
			current++;
		if (current == needle_len)
			return ((char *)(haystack + start));
		start++;
	}
	return (0);
}
