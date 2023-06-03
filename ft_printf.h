/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:44:02 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/03 14:14:19 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	handle_char(char c, int fd);
int	ft_print_hex(void *ptr);
int	handle_unsigned_int(unsigned int n, int fd);
int	handle_signed_int(int n, int fd);
int	handle_int_hex(unsigned int value, int upper, int fd);
int	handle_string(char *str);

#endif