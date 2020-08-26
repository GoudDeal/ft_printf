/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:20:46 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:36:00 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	ft_initialize(t_format *format)
{
	format->type = 0;
	format->padding = 0;
	format->inversed = 0;
	format->width = 0;
	format->prec_size = 0;
	format->precision = 0;
	format->fill = 32;
	format->precision_star = 0;
	format->width_star = 0;
	format->writecount = 0;
	format->width = 0;
	format->min = 0;
	format->precision_default = 0;
	format->int_zero = 0;
	format->set_min = 0;
	format->set_width = 0;
	return (*format);
}

t_format	ft_reset(t_format format)
{
	format.type = 0;
	format.padding = 0;
	format.inversed = 0;
	format.width = 0;
	format.prec_size = 0;
	format.precision_default = 0;
	format.precision = 0;
	format.fill = 32;
	format.precision_star = 0;
	format.width_star = 0;
	format.width = 0;
	format.min = 0;
	format.int_zero = 0;
	format.set_min = 0;
	format.set_width = 0;
	return (format);
}
