/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:12:53 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 13:24:26 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_unsigned_int(unsigned int n, int fd)
{
	int	count;
	char	c;

	if (n > 9)
	{
		count = handle_unsigned_int(n / 10, fd);
		c = '0' + n % 10;
		return (count + write(fd, &c, 1));
	}
	else
	{
		c = '0' + n;
		return (write(fd, &c, 1));
	}
}

int	handle_signed_int(int n, int fd)
{
	int	count;
	char	c;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
		count = handle_signed_int(n, fd);
		return (count + 1);
	}
	if (n > 9)
	{
		count = handle_signed_int(n / 10, fd);
		c = '0' + n % 10;
		return (count + write(fd, &c, 1));
	}
	else
	{
		c = '0' + n;
		return (write(fd, &c, 1));
	}
}
