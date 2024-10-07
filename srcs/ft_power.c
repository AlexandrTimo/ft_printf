/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power(int a, int b)
{
	long	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}

double	ft_power_d(double a, int b)
{
	double	power;

	power = 1;
	while (b > 0)
	{
		power *= a;
		--b;
	}
	return (power);
}
