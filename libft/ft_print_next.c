/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:26:40 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:43:02 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_unsigned(t_format format, va_list *va)
{
	unsigned int		arg;
	char				*str;

	arg = va_arg(*va, unsigned int);
	str = ft_itoa_unsigned(arg);
	format = ft_set_precision_unsigned(format, arg);
	format = ft_set_padding_unsigned(format, arg);
	if (format.inversed)
	{
		format.writecount = ft_putstr_unsigned(str, 1, format, arg);
		format.writecount = ft_print_padding_unsigned(format, arg);
		free(str);
		return (format.writecount);
	}
	format.writecount = ft_print_padding_unsigned(format, arg);
	format.writecount = ft_putstr_unsigned(str, 1, format, arg);
	free(str);
	return (format.writecount);
}

int		ft_print_pourcent(t_format format)
{
	(void)format;
	if (format.width && format.inversed)
	{
		format.writecount = ft_putchar_fd('%', 1, format);
		format.padding = format.width - 1;
		while (format.padding--)
			format.writecount = ft_putchar_fd(' ', 1, format);
		return (format.writecount);
	}
	if (format.width)
	{
		format.padding = format.width - 1;
		while (format.padding--)
			format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.writecount = ft_putchar_fd('%', 1, format);
		return (format.writecount);
	}
	format.writecount = ft_putchar_fd('%', 1, format);
	return (format.writecount);
}

int		ft_print_hex(t_format format, va_list *va)
{
	int			arg;

	arg = va_arg(*va, int);
	format = ft_set_precision_hexa(format, arg);
	format = ft_set_padding_hexa(format, arg);
	if (format.inversed)
	{
		while (format.prec_size-- > 0)
			format.writecount = ft_putchar_fd('0', 1, format);
		format.writecount = ft_putnbr_base(arg, HEXA, format);
		format.writecount = ft_print_padding_unsigned(format, arg);
		return (format.writecount);
	}
	if (format.padding)
		format.writecount = ft_print_padding_unsigned(format, arg);
	while (format.prec_size-- > 0)
		format.writecount = ft_putchar_fd('0', 1, format);
	format.writecount = ft_putnbr_base(arg, HEXA, format);
	return (format.writecount);
}

int		ft_print_hex_maj(t_format format, va_list *va)
{
	int			arg;

	arg = va_arg(*va, int);
	format = ft_set_precision_hexa(format, arg);
	format = ft_set_padding_hexa(format, arg);
	if (format.inversed)
	{
		while (format.prec_size-- > 0)
			format.writecount = ft_putchar_fd('0', 1, format);
		format.writecount = ft_putnbr_base(arg, HEXA_MAJ, format);
		format.writecount = ft_print_padding_unsigned(format, arg);
		return (format.writecount);
	}
	if (format.padding)
		format.writecount = ft_print_padding_unsigned(format, arg);
	while (format.prec_size-- > 0)
		format.writecount = ft_putchar_fd('0', 1, format);
	format.writecount = ft_putnbr_base(arg, HEXA_MAJ, format);
	return (format.writecount);
}

int		ft_print_null(t_format format, char *arg)
{
	(void)arg;
	format = ft_set_precision_null(format);
	format = ft_set_padding_null(format);
	if (format.inversed)
	{
		format.writecount = ft_putstr_fd("(null)", 1, format);
		format.writecount = ft_print_padding_null(format);
		return (format.writecount);
	}
	format.writecount = ft_print_padding_null(format);
	format.writecount = ft_putstr_fd("(null)", 1, format);
	return (format.writecount);
}
