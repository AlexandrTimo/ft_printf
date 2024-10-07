/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	j = ft_getnbsize(n);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == 0)
		return (0);
	str[j] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < j--)
	{
		str[j] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
