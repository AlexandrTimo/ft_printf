/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftosn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 10:11:26 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/05/23 17:22:32 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nbrcpy_p(long nb, int precision, char *str)
{
	long int	multiplier;
	int			len;
	int			i;

	len = ft_numberlen(nb);
	i = 0;
	multiplier = ft_power(10, len - 1);
	while (str[i] && i < precision)
	{
		if (i < (precision - len))
			str[i] = '0';
		else
		{
			str[i] = ((nb / multiplier) % 10) * ((nb < 0) ? -1 : 1) + '0';
			multiplier = multiplier / 10;
		}
		++i;
	}
}

static t_fp		get_parts(double nb, int *exponent, int precision)
{
	t_fp	f;
	int		len;

	if (precision > 15)
		precision = 15;
	len = ft_numberlen((long)nb);
	while (nb && (nb > (1UL << 63) || len != precision + 1))
	{
		if (nb > (1UL << 63) || len > precision + 1)
		{
			nb /= 10;
			++(*exponent);
		}
		else
		{
			nb *= 10;
			--(*exponent);
		}
		len = ft_numberlen((long)nb);
	}
	f.integral = ft_round(nb) / ft_power(10, precision);
	f.fraction = ft_round(nb) - (f.integral * (long)ft_power(10, precision));
	if (nb)
		*exponent += precision;
	return (f);
}

static char		*make_string(t_fp f, int sign, int exponent, int precision)
{
	char	*str;
	char	*cur;

	str = ft_strinitial(sign + 3 + ((precision) ? precision + 1 : 0) +
		((ft_numberlen(exponent) < 2) ? 2 : ft_numberlen(exponent)), '0');
	cur = str;
	if (sign)
		*cur++ = '-';
	*cur++ = f.integral + '0';
	if (precision)
	{
		*cur++ = '.';
		if (precision > 15)
			nbrcpy_p(f.fraction, 15, cur);
		else
			nbrcpy_p(f.fraction, precision, cur);
	}
	if (exponent >= 0)
		ft_strncpy(str + sign + ((precision) ? precision + 1 : 0) + 1, "e+", 2);
	else
		ft_strncpy(str + sign + ((precision) ? precision + 1 : 0) + 1, "e-", 2);
	cur = str + ft_strlen(str) - ft_numberlen(exponent);
	nbrcpy_p(exponent, ft_numberlen(exponent), cur);
	return (str);
}

char			*ft_ftosn(double nb, int precision)
{
	t_double	doub;
	t_fp		f;
	int			sign;
	int			exp;
	long		mantissa;

	doub.d = nb;
	sign = (doub.l >> 63) & 1;
	exp = ((doub.l >> 52) & 0x7ff);
	mantissa = (doub.l & 0x000fffffffffffff);
	if (exp == 0x7ff)
	{
		if (mantissa)
			return (ft_strdup("nan"));
		else
			return (ft_strdup((sign) ? "-inf" : "inf"));
	}
	exp = 0;
	f = get_parts((nb < 0 ? (nb * -1) : nb), &exp, precision);
	return (make_string(f, sign, exp, precision));
}
