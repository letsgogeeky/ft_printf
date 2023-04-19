/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:36:25 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/24 11:52:41 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *c)
{
	int	size;

	size = 0;
	while (c[size] != '\0')
	{
		size++;
	}
	return (size);
}
