/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:51 by ramoussa          #+#    #+#             */
/*   Updated: 2023/04/19 19:01:37 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int	first_arg, second_arg, third_arg, fourth_arg;
	va_start(params, str);

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