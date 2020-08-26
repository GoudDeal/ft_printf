/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:25:06 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/26 14:34:18 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format		ft_set_precision_str(t_format format, char *arg)
{
	if (format.precision)
	{
		if (format.min == 0 && format.precision_star != 1)
			format.prec_size = 0;
		if (format.min < 0)
			format.prec_size = (int)ft_strlen(arg);
		else if (format.min < (int)ft_strlen(arg))
			format.prec_size = format.min;
		if (format.min >= (int)ft_strlen(arg))
			format.prec_size = (int)ft_strlen(arg);
	}
	else
		format.prec_size = (int)ft_strlen(arg);
	return (format);
}

t_format		ft_set_padding_str(t_format format, char *arg)
{
	(void)arg;
	if (format.width > format.prec_size)
		format.padding = format.width - format.prec_size;
	return (format);
}

t_format		ft_set_padding_int(t_format format, int arg)
{
	int		size;

	size = ft_size_int(arg);
	if (arg < 0)
		size += 1;
	if (format.precision == 1 || format.inversed)
	{
		if ((format.fill == '0' && format.min != 0) || format.inversed)
			format.fill = ' ';
	}
	if (format.int_zero)
	{
		format.padding = format.width;
		return (format);
	}
	if (format.width > format.prec_size)
		format.padding = format.width - (size + format.prec_size);
	else if (format.width <= 0)
		format.padding = 0;
	else if (format.width < (size + format.prec_size))
		format.padding = 0;
	else
		format.padding = (format.width - size) - format.prec_size;
	return (format);
}

int				ft_set_padding_ptr(t_format format, long int arg)
{
	if (arg < 0)
	{
		if (format.width > 17)
			format.padding = format.width - 18;
		else
			format.padding = 0;
		return (format.padding);
	}
	if (arg == 1)
		format.padding = format.width - 3;
	else if (arg == 0)
		format.padding = format.width - 3;
	else if (ft_size_hexa(arg) < 8)
		format.padding = format.width - (2 + ft_size_hexa(arg));
	else if (format.width > 14)
		format.padding = format.width - (2 + ft_size_hexa(arg));
	else
		format.padding = 0;
	return (format.padding);
}

t_format		ft_set_precision_int(t_format format, int arg)
{
	if (format.precision == 1)
	{
		if (format.min < 0)
		{
			format.min = 0;
			format.prec_size = 0;
			return (format);
		}
		format.fill = ' ';
		if (format.min == 0 && arg == 0)
			format.int_zero = 1;
		if (format.precision_star && format.min == 0 && arg == 0)
			format.int_zero = 1;
		if (arg < 0)
			format.prec_size = format.min - (ft_size_int(arg));
		else if (format.min > ft_size_int(arg))
			format.prec_size = format.min - ft_size_int(arg);
	}
	if (format.prec_size < 0)
		format.prec_size = 0;
	return (format);
}
