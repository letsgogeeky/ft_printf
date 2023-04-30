/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:51 by ramoussa          #+#    #+#             */
/*   Updated: 2023/04/28 16:47:15 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	handle_hex(unsigned long ptr, int len)
{
	char	c;
	
	if (!ptr)
		return (len);
	len = handle_hex(ptr / 16, len + 1);
	c = ptr % 16;
	if (c < 10)
		ft_putchar_fd(c + '0', 1);
	else
		ft_putchar_fd(c + 'a' - 10, 1);
	return (len);
}

int ft_print_str(va_list params)
{
	char	*str;
	size_t	len;

	str = va_arg(params, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
		
	len = ft_strlen(str);
	write(1, str, sizeof(char) * len);
	return (len);
}

int ft_print_hex(va_list params)
{
	void	*ptr;

	ptr = va_arg(params, void *);
	write(1, "0x", 2);
	if (!ptr)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	return (2 + handle_hex((long)ptr, 0));
}

int	type_factory(va_list params, char fmt)
{
	if (fmt == 'c')
	{
		ft_putchar_fd(va_arg(params, int), 1);
		return (1);
	}
	else if (fmt == 's')
	{
		return (ft_print_str(params));
	}
	else if (fmt == 'p')
	{
		return (ft_print_hex(params));
	}
	else if (fmt == 'd')
		ft_putnbr_fd(va_arg(params, int), 1);
	else if (fmt == 'u')
	{
		// unsigned decimal
	}
	else if (fmt == 'x')
	{
		// print a number in hexadecimal format (lowercase)
	}
	else if (fmt == 'X')
	{
		// print a number in hexadecimal format (uppercase)
		
	}
	else if (fmt == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int	i;
	int len;
		
	if (!str)
		return (-1);
	va_start(params, str);
	i = 0;
	len = 0;
	while(str && str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len += type_factory(params, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	return (len);
}

