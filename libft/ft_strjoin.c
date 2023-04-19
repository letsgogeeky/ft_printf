/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:38:45 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/26 12:49:22 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_size;
	unsigned int	s2_size;
	char			*str;
	unsigned int	str_idx;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str_idx = 0;
	str = (char *)malloc(s1_size + s2_size + 1);
	if (str == 0)
		return (0);
	while (*s1 != '\0')
	{
		str[str_idx] = *s1;
		s1++;
		str_idx++;
	}
	while (*s2 != '\0')
	{
		str[str_idx] = *s2;
		s2++;
		str_idx++;
	}
	str[str_idx] = '\0';
	return (str);
}
