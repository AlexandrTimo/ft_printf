/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;
	char		*combine;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	combine = combine_list(strs, total_len);
	write(1, combine, total_len);
	ft_lstdel(&strs, ft_lstmemdel);
	ft_strdel(&combine);
	va_end(args);
	return (total_len);
}

int					ft_printfd(int fd, const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;
	char		*combine;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	combine = combine_list(strs, total_len);
	write(fd, combine, total_len);
	ft_lstdel(&strs, ft_lstmemdel);
	ft_strdel(&combine);
	va_end(args);
	return (total_len);
}

int					ft_sprintf(char **str, const char *format, ...)
{
	va_list		args;
	t_list		*strs;
	size_t		total_len;

	va_start(args, format);
	strs = 0;
	total_len = create_list(&strs, format, args);
	*str = combine_list(strs, total_len);
	ft_lstdel(&strs, ft_lstmemdel);
	va_end(args);
	return (total_len);
}
