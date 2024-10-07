/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numberlen_sign_base(long long num, int base)
{
	int length;

	length = 1;
	if (num < 0)
	{
		num *= -1;
		++length;
	}
	while (num >= base)
	{
		num /= base;
		++length;
	}
	return (length);
}

size_t	ft_numberlen_base(long long num, int base)
{
	int length;

	length = 1;
	while (num >= base || num <= -base)
	{
		num /= base;
		++length;
	}
	return (length);
}

size_t	ft_unumberlen_base(unsigned long long nb, int base)
{
	int length;

	length = 1;
	while (nb >= (unsigned int)base)
	{
		nb /= base;
		++length;
	}
	return (length);
}
