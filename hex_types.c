/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:11:57 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/05 20:59:07 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_long_hex(unsigned long value, int upper, int fd)
{
	char	*upperhex;
	char	*lowerhex;
	char	*model;
	int		count;
	int		written;

	upperhex = "0123456789ABCDEF";
	lowerhex = "0123456789abcdef";
	if (upper)
		model = (char *)upperhex;
	else
		model = (char *)lowerhex;
	if (value > 15)
	{
		count = handle_long_hex(value / 16, upper, fd);
		if (count == -1)
			return (-1);
		written = write(fd, &model[value % 16], 1);
		if (written == -1)
			return (-1);
		return (count + written);
	}
	else
		return (write(fd, &model[value], 1));
}

int	handle_int_hex(unsigned int value, int upper, int fd)
{
	char	*upperhex;
	char	*lowerhex;
	char	*model;
	int		count;
	int		written;

	upperhex = "0123456789ABCDEF";
	lowerhex = "0123456789abcdef";
	if (upper)
		model = (char *)upperhex;
	else
		model = (char *)lowerhex;
	if (value > 15)
	{
		count = handle_int_hex(value / 16, upper, fd);
		if (count == -1)
			return (-1);
		written = write(fd, &model[value % 16], 1);
		if (written == -1)
			return (-1);
		return (count + written);
	}
	else
		return (write(fd, &model[value], 1));
}

int	ft_print_hex(void *ptr)
{
	int	written;

	written = write(1, "0x", 2);
	if (written == -1)
		return (-1);
	if (!ptr)
	{
		return (written + write(1, "0", 1));
	}
	return (written + handle_long_hex((unsigned long)ptr, 0, 1));
}
