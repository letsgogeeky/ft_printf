/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:51 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 21:56:07 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_factory(va_list *params, char fmt)
{
	if (fmt == 'c')
		return (handle_char((char)va_arg(*params, int), 1));
	else if (fmt == 's')
		return (handle_string(va_arg(*params, char *)));
	else if (fmt == 'p')
		return (ft_print_hex(va_arg(*params, void *)));
	else if (fmt == 'd')
		return (handle_signed_int(va_arg(*params, int), 1));
	else if (fmt == 'i')
		return (handle_signed_int(va_arg(*params, int), 1));
	else if (fmt == 'u')
		return (handle_unsigned_int(va_arg(*params, unsigned int), 1));
	else if (fmt == 'x')
		return (handle_int_hex(va_arg(*params, unsigned int), 0, 1));
	else if (fmt == 'X')
		return (handle_int_hex(va_arg(*params, unsigned int), 1, 1));
	else if (fmt == '%')
		return (write(1, "%", 1));
	return (0);
}

int	process_params(const char *str, va_list *params)
{
	int	i;
	int len;
	int	written;

	i = 0;
	len = 0;
	while(str && str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			written = type_factory(params, str[i + 1]);
			len += written;
			i++;
		}
		else
		{
			written = write(1, &str[i], 1);
			len += written;
		}
		if (written < 0)
			return (-1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int	len;

	va_start(params, str);
	len = process_params(str, &params);	
	va_end(params);
	return (len);
}
