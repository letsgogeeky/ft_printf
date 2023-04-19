/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 15:29:30 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/28 11:37:24 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_digits(int n)
{
	int		digit_count;

	digit_count = 0;
	if (n <= 0)
		digit_count++;
	while (n)
	{
		n = n / 10;
		digit_count++;
	}
	return (digit_count);
}

static char	*make_str(char *str, unsigned int n, int digit_count)
{
	while (n)
	{
		str[digit_count] = n % 10 + '0';
		n = n / 10;
		digit_count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit_count;
	int		idx;

	digit_count = count_digits(n);
	str = (char *)malloc(sizeof(char) * digit_count + 1);
	if (!str)
		return (0);
	idx = 0;
	str[digit_count] = '\0';
	digit_count--;
	if (n == 0)
	{
		str[digit_count] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str = make_str(str, (unsigned int)n, digit_count);
	return (str);
}
