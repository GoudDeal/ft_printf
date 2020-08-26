/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_padding_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:11:09 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:47:14 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format		ft_set_padding_unsigned(t_format format, unsigned int arg)
{
	if (format.inversed)
		format.fill = ' ';
	if (format.int_zero)
	{
		format.padding = format.width;
		format.fill = ' ';
		return (format);
	}
	if (format.width > (ft_size_uns(arg) + format.prec_size))
		format.padding = format.width - (ft_size_uns(arg) + format.prec_size);
	else if (format.width <= 0)
		format.padding = 0;
	else if (format.width < (ft_size_uns(arg) + format.prec_size))
		format.padding = 0;
	else
		format.padding = (format.width - ft_size_uns(arg)) - format.prec_size;
	return (format);
}

t_format		ft_set_precision_unsigned(t_format format, unsigned int arg)
{
	if (format.precision)
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
		else if (format.min > ft_size_uns(arg))
			format.prec_size = format.min - ft_size_uns(arg);
	}
	if (format.prec_size < 0)
		format.prec_size = 0;
	return (format);
}

t_format		ft_set_precision_hexa(t_format format, long int arg)
{
	unsigned int	arg_unsigned;

	arg_unsigned = arg;
	if (format.precision)
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
		else if (format.min > ft_size_hexa(arg_unsigned))
			format.prec_size = format.min - ft_size_hexa(arg_unsigned);
	}
	if (format.prec_size < 0)
		format.prec_size = 0;
	return (format);
}

t_format		ft_set_padding_hexa(t_format format, long int arg)
{
	unsigned int	a_u;

	a_u = arg;
	if (format.inversed)
		format.fill = ' ';
	if (format.int_zero)
	{
		format.padding = format.width;
		format.fill = ' ';
		return (format);
	}
	if (format.width > (ft_size_hexa(a_u) + format.prec_size))
		format.padding = format.width - (ft_size_hexa(a_u) + format.prec_size);
	else if (format.width <= 0)
		format.padding = 0;
	else if (format.width < (ft_size_hexa(a_u) + format.prec_size))
		format.padding = 0;
	else
		format.padding = (format.width - ft_size_hexa(a_u)) - format.prec_size;
	return (format);
}

t_format		ft_set_precision_ptr(t_format format, long int arg)
{
	if (format.precision)
	{
		if (arg == 0)
		{
			format.precision = 0;
			format.prec_size = 0;
			return (format);
		}
		if (format.min > ft_size_hexa(arg))
			format.prec_size = format.min - ft_size_hexa(arg);
		return (format);
	}
	return (format);
}
