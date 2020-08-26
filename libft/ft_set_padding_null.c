/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_padding_null.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:04:21 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:28:06 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	ft_set_precision_null(t_format format)
{
	if (format.precision)
	{
		if (format.min < 0)
			format.prec_size = 6;
		else if (format.min < 6)
			format.prec_size = format.min;
		else
			format.prec_size = 6;
	}
	return (format);
}

t_format	ft_set_padding_null(t_format format)
{
	if (format.precision)
	{
		if (format.prec_size == 0)
			format.padding = format.width;
		else
			format.padding = format.width - format.prec_size;
	}
	else
	{
		if (format.width > 6)
			format.padding = format.width - 6;
	}
	return (format);
}
