/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(const wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static int	get_bytes(wchar_t wc)
{
	int		i;

	i = 32;
	while (i > 0 && !(wc >> (i - 1)))
		--i;
	return ((i > 7) ? ((i + 3) / 5) : 1);
}

char		*conv_utf8_char(wchar_t wchar, char *str)
{
	char	*cur;
	int		bytes;

	bytes = get_bytes(wchar);
	if (!str && wchar)
		str = ft_strnew(bytes);
	if (!wchar || !str)
		return ((!wchar) ? ft_strnew(1) : 0);
	cur = str + bytes - 1;
	if (bytes > 1)
		while (cur >= str)
		{
			*cur |= (!(cur - str) ? (0xFF << (8 - bytes)) : 0x80);
			*cur |= (wchar & 0x3F);
			wchar = wchar >> 6;
			cur = (cur - str) ? (cur - 1) : 0;
		}
	else
		*cur = (char)wchar;
	return (str);
}

char		*conv_utf8_str(wchar_t *wstr)
{
	char	*str;
	int		bytes;
	int		totalbytes;

	if (!wstr)
		return (0);
	totalbytes = 0;
	while (wstr && *wstr)
		totalbytes += get_bytes(*wstr++);
	str = ft_strnew(totalbytes);
	str += totalbytes;
	while (totalbytes)
	{
		--wstr;
		bytes = get_bytes(*wstr);
		totalbytes -= bytes;
		str -= bytes;
		str = conv_utf8_char(*wstr, str);
	}
	return (str);
}
