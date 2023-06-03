/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:10:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 14:13:22 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_char(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int handle_string(char *str)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
		
	len = ft_strlen(str);
	write(1, str, sizeof(char) * len);
	return (len);
}