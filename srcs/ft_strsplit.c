/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**arr;

	i = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * ft_strlen(s));
	if (!arr)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			arr[i] = ft_strsub(s, 0, ft_size_of_word(s, c));
			s = s + ft_size_of_word(s, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
