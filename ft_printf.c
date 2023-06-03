/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:51 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 14:17:20 by ramoussa         ###   ########.fr       */
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
	else
		return (0);
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
			len += type_factory(&params, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(params);
	return (len);
}
