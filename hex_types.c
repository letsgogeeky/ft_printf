/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:11:57 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 14:10:34 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_long_hex(unsigned long value, int upper, int fd)
{
	char	*upperhex = "0123456789ABCDEF";
	char	*lowerhex = "0123456789abcdef";
	char	*model;
	int		count;

	if (upper)
		model = (char *)upperhex;
	else
		model = (char *)lowerhex;
	if (value > 15)
	{
		count = handle_long_hex(value / 16, upper, fd);
		return (count + write(fd, &model[value % 16], 1));
	}
	else
		return (write(fd, &model[value], 1));
}

int	handle_int_hex(unsigned int value, int upper, int fd)
{
	char	*upperhex = "0123456789ABCDEF";
	char	*lowerhex = "0123456789abcdef";
	char	*model;
	int		count;

	if (upper)
		model = (char *)upperhex;
	else
		model = (char *)lowerhex;
	if (value > 15)
	{
		count = handle_int_hex(value / 16, upper, fd);
		return (count + write(fd, &model[value % 16], 1));
	}
	else
		return (write(fd, &model[value], 1));
}

int ft_print_hex(void *ptr)
{
	write(1, "0x", 2);
	if (!ptr)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	return (2 + handle_long_hex((unsigned long)ptr, 0, 1));
}
