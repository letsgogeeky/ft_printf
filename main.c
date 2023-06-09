/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:25:30 by ramoussa          #+#    #+#             */
/*   Updated: 2023/06/10 01:09:15 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	get_first_chr(char *str)
{
	if (!str)
		return (0);
	return str[0];
}

int	main()
{
	void	*f = get_first_chr;
	ft_printf("H %d el %% lo %c World %c || %s    || %p\n", 421232112, '2', 's', "HEEEEY", f);
	printf("H %d el %% lo %c World %c || %s    || %p\n", 421232112, '2', 's', "HEEEEY", f);

	ft_printf("%%\n");
	printf("%%\n");

	ft_printf("%\n");
	printf("%\n");
	return (0);
}
