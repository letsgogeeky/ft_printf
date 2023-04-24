/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:51 by ramoussa          #+#    #+#             */
/*   Updated: 2023/04/24 23:00:21 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	handle_hex(unsigned long ptr, int to_upper)
{
	char	*hex_set;
	int		len;
	char	c;
	hex_set = "0123456789abcdef";
	// write(1, "0x", 2);
	// len = 2;
	len = 0;
	if (ptr > 0 && ptr <= 15)
	{
		c = ptr;
		len += 1;
	}
	else if (ptr > 0)
	{
		c = ptr % 16;
		len += handle_hex(ptr / 16, to_upper);
	}
	if (to_upper == 1 && c > 9)
		write(1, &hex_set[(int)c] - 32, 1);
	else
		write(1, &hex_set[(int)c], 1);
	return (len);
}

int	type_factory(va_list params, char fmt)
{
	if (fmt == 'c')
		ft_putchar_fd(va_arg(params, int), 1);
	else if (fmt == 's')
		ft_putstr_fd(va_arg(params, char *), 1);
	else if (fmt == 'p')
	{
		// check how to print a pointer in hexadecimal
		write(1, "0x", 2);
		handle_hex((unsigned long)va_arg(params, void *), 0);
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
		write(1, "0x", 2);
		handle_hex((unsigned long)va_arg(params, long), 1);
	}
	else if (fmt == '%')
		ft_putchar_fd('%', 1);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int	i;
	// int	first_arg, second_arg, third_arg, fourth_arg;
	
	if (!str)
		return (-1);
	va_start(params, str);
	i = 0;
	while(str && str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			type_factory(params, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 0);
		}
		i++;
	}
	// type_factory(params, 'd');
	// first_arg = va_arg(params, int);
	// printf("FOUND IT!! HERE: %d\n", first_arg);
	// second_arg = va_arg(params, int);
	// printf("WE TRIED TO CAST THIS TO INT: %d\n", second_arg);
	// third_arg = va_arg(params, int);
	// printf("WE TRIED TO CAST ANOTHER CHAR TO INT: %d\n", third_arg);
	// fourth_arg = va_arg(params, int);
	// printf("WE TRIED TO CAST A CHAR ARRAY TO INT HAHAH!! %d\n", fourth_arg);
	return (0);
}

