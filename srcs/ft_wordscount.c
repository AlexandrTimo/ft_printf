/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordscount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordscount(char const *str, char c)
{
	size_t	count;
	int		inside_a_word;

	inside_a_word = 0;
	count = 0;
	while (*str)
	{
		if (!inside_a_word && *str != c)
			count++;
		inside_a_word = (*str == c) ? 0 : 1;
		str++;
	}
	return (count);
}
