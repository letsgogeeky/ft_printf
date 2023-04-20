/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:51 by ramoussa          #+#    #+#             */
/*   Updated: 2023/04/19 23:37:32 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	type_factory(va_list params, char fmt)
{
	if (fmt == 'c')
		ft_putchar_fd(va_arg(params, int), 1);
	else if (fmt == 's')
		ft_putstr_fd(va_arg(params, char *), 1);
	else if (fmt == 'p')
	{
		// check how to print a pointer in hexadecimal
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
		ft_putchar_fd('%', 1);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int	first_arg, second_arg, third_arg, fourth_arg;
	va_start(params, str);

	type_factory(params, 'd');
	first_arg = va_arg(params, int);
	printf("FOUND IT!! HERE: %d\n", first_arg);
	second_arg = va_arg(params, int);
	printf("WE TRIED TO CAST THIS TO INT: %d\n", second_arg);
	third_arg = va_arg(params, int);
	printf("WE TRIED TO CAST ANOTHER CHAR TO INT: %d\n", third_arg);
	fourth_arg = va_arg(params, int);
	printf("WE TRIED TO CAST A CHAR ARRAY TO INT HAHAH!! %d\n", fourth_arg);
	return (0);
}

