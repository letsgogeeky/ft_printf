/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:10:04 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 21:50:50 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_char(char c, int fd)
{
	return (write(fd, &c, 1));
}

int handle_string(char *str)
{
	size_t	len;
	int		written;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	len = ft_strlen(str);
	written = write(1, str, sizeof(char) * len);
	if (written == -1)
		return (-1);
	return (len);
}
