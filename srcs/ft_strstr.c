/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *string1, const char *string2)
{
	int pos;
	int i;

	if (!*string2)
		return ((char *)string1);
	pos = 0;
	while (string1[pos] != '\0')
	{
		if (string1[pos] == string2[0])
		{
			i = 1;
			while (string2[i] != '\0' && string1[pos + i] == string2[i])
				++i;
			if (string2[i] == '\0')
				return ((char *)&string1[pos]);
		}
		++pos;
	}
	return (0);
}
