/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:18:10 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:33:10 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_precision_int(t_format format, int arg)
{
	if (arg < 0 && format.inversed)
	{
		format.writecount = ft_putchar_fd('-', 1, format);
		if (format.precision)
		{
			while (format.prec_size-- > 0)
				format.writecount = ft_putchar_fd('0', 1, format);
		}
		return (format.writecount);
	}
	if (format.precision)
	{
		while (format.prec_size-- > 0)
			format.writecount = ft_putchar_fd('0', 1, format);
	}
	return (format.writecount);
}

int		ft_print_precision_ptr(t_format format, long int arg)
{
	(void)arg;
	if (format.precision)
	{
		while (format.prec_size-- > 0)
			format.writecount = ft_putchar_fd('0', 1, format);
	}
	return (format.writecount);
}
