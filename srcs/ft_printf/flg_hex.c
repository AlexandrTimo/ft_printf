/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flg_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static unsigned long long	take_num(char length, va_list args)
{
	unsigned long long		num;

	num = 0;
	if (length == 0)
		num = va_arg(args, unsigned int);
	else if (length == 'l')
		num = va_arg(args, unsigned long);
	else if (length == 'L')
		num = va_arg(args, unsigned long long);
	else if (length == 'h')
		num = (unsigned short)va_arg(args, unsigned int);
	else if (length == 'H')
		num = (unsigned char)va_arg(args, unsigned int);
	else if (length == 'j')
		num = va_arg(args, unsigned long long);
	else if (length == 'z')
		num = va_arg(args, size_t);
	return (num);
}

static void					append_flags(char *str, t_format *frmt,
											unsigned long long num, int len)
{
	if (!(frmt->flags & MINUS))
		str += (frmt->width - frmt->precision);
	if (len)
	{
		if (frmt->flags & SHARP && num != 0)
		{
			ft_strncpy(str, "0x", 2);
			str += 2;
		}
		while (str && *str == ' ')
			*str++ = '0';
	}
}

static void					ft_numcpy_hex(unsigned long long num, char *str)
{
	if (num >= 16)
		ft_numcpy_hex(num / 16, str - 1);
	if ((num % 16) >= 10)
		*str = ((num % 16) + 'a' - 10);
	else
		*str = ((num % 16) + '0');
}

static char					*num_format(t_format *frmt,
		unsigned long long num, int len)
{
	if (frmt->flags & SHARP && num != 0)
		len += 2;
	if (frmt->precision != -1)
	{
		if (frmt->precision < len)
			frmt->precision = len;
		if (frmt->precision > frmt->width)
			frmt->width = frmt->precision;
	}
	else
	{
		frmt->width = ft_max(frmt->width, len);
		frmt->precision = len;
		if (frmt->flags & ZERO)
			frmt->precision = frmt->width;
	}
	return (ft_strinitial(frmt->width, ' '));
}

char						*flg_hex(t_format *frmt, va_list args)
{
	char					*new;
	unsigned long long		num;
	int						len;

	num = take_num(frmt->lenght, args);
	if (frmt->precision == 0 && num == 0)
		len = 0;
	else
		len = ft_unumberlen_base(num, 16);
	new = num_format(frmt, num, len);
	if (len)
	{
		if (frmt->flags & MINUS)
			ft_numcpy_hex(num, new + (frmt->precision - 1));
		else
			ft_numcpy_hex(num, new + (frmt->width - 1));
	}
	append_flags(new, frmt, num, len);
	if (ft_isupper(frmt->conv))
		ft_strupper(new);
	return (new);
}
