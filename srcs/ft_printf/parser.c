/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					get_conv(const char **format, t_format *frmt_struct)
{
	const char		*flags;
	char			*index;

	flags = CONV;
	if (**format && (index = ft_strchr(flags, **format)))
	{
		(*format)++;
		frmt_struct->conv = *index;
		return (index - flags);
	}
	return (-1);
}

void				parse_size_flag(const char **format, t_format *frmt_struct)
{
	const char		*flags;
	const char		*sub;

	flags = "hHlLjz";
	if (**format && (sub = ft_strchr(flags, **format)))
	{
		if (**format == 'h' && *(*format + 1) == 'h')
		{
			frmt_struct->lenght = 'H';
			++(*format);
		}
		else if (**format == 'l' && *(*format + 1) == 'l')
		{
			frmt_struct->lenght = 'L';
			++(*format);
		}
		else
			frmt_struct->lenght = *sub;
		++(*format);
	}
}

void				parse_width_precis(const char **format,
		t_format *frmt_struct, va_list args)
{
	if (*format)
	{
		if (**format == '*' && ++(*format))
			frmt_struct->width = va_arg(args, int);
		else if (ft_isdigit(**format))
		{
			frmt_struct->width = ft_atoi(*(char **)format);
			while (*format && ft_isdigit(**format))
				++(*format);
		}
	}
	if (**format && **format == '.')
	{
		++(*format);
		if (**format == '*' && ++(*format))
			frmt_struct->precision = va_arg(args, int);
		else if (ft_isdigit(**format))
		{
			frmt_struct->precision = ft_atoi(*(char **)format);
			while (*format && ft_isdigit(**format))
				++(*format);
			if (frmt_struct->precision < 0)
				frmt_struct->precision = 0;
		}
	}
}

void				parse_flags(const char **format, t_format *frmt_struct)
{
	const char		*flags;
	const char		*cur;
	unsigned char	ret;

	flags = "#0-+ ";
	ret = 0;
	while (**format && (cur = ft_strchr(flags, **format)))
	{
		ret = ret | (1 << (cur - flags));
		++(*format);
	}
	ret = ((ret & (ZERO | MINUS)) == (ZERO | MINUS) ? (ret ^ ZERO) : ret);
	ret = ((ret & (SPACE | PLUS)) == (SPACE | PLUS) ? (ret ^ SPACE) : ret);
	frmt_struct->flags = ret;
}
