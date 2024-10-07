/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numberlen_sign(long long num)
{
	size_t	length;

	length = 1;
	if (num < 0)
	{
		num *= -1;
		++length;
	}
	while (num >= 10)
	{
		num /= 10;
		++length;
	}
	return (length);
}

size_t		ft_numberlen(long long num)
{
	size_t	length;

	length = 1;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		++length;
	}
	return (length);
}

size_t		ft_unumberlen(unsigned long long num)
{
	size_t	length;

	length = 1;
	while (num >= 10)
	{
		num /= 10;
		++length;
	}
	return (length);
}
