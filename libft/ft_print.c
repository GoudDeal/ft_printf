/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:22:05 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:42:40 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_print(t_format format, va_list *va)
{
	if (format.type != 0)
	{
		if (format.type == 'c')
			return (ft_print_char(format, va));
		if (format.type == 's')
			return (ft_print_str(format, va));
		if (format.type == 'p')
			return (ft_print_ptr(format, va));
		if (format.type == 'd' || format.type == 'i')
			return (ft_print_int(format, va));
		if (format.type == 'u')
			return (ft_print_unsigned(format, va));
		if (format.type == 'x')
			return (ft_print_hex(format, va));
		if (format.type == 'X')
			return (ft_print_hex_maj(format, va));
		if (format.type == '%')
			return (ft_print_pourcent(format));
	}
	return (format.writecount);
}

int			ft_print_char(t_format format, va_list *va)
{
	int		arg;

	arg = va_arg(*va, int);
	if (format.inversed == 1)
	{
		format.writecount = ft_putchar_fd(arg, 1, format);
		format.writecount = ft_print_padding_char(format);
	}
	else
	{
		format.writecount = ft_print_padding_char(format);
		format.writecount = ft_putchar_fd(arg, 1, format);
	}
	return (format.writecount);
}

int			ft_print_str(t_format format, va_list *va)
{
	char	*arg;

	arg = va_arg(*va, char*);
	if (arg == NULL)
		return (format.writecount = ft_print_null(format, "(null)"));
	format = ft_set_precision_str(format, arg);
	format = ft_set_padding_str(format, arg);
	if (format.inversed)
	{
		format.writecount = ft_putstr_fd(arg, 1, format);
		format.writecount = ft_print_padding_str(format, arg);
		return (format.writecount);
	}
	format.writecount = ft_print_padding_str(format, arg);
	format.writecount = ft_putstr_fd(arg, 1, format);
	return (format.writecount);
}

int			ft_print_ptr(t_format format, va_list *va)
{
	long int		arg;

	arg = va_arg(*va, long int);
	format = ft_set_precision_ptr(format, arg);
	format.padding = ft_set_padding_ptr(format, arg);
	if (format.inversed == 1)
	{
		format.writecount = ft_putptr_fd(arg, 1, format);
		if (arg != 0)
		{
			format.writecount = ft_print_precision_ptr(format, arg);
			format.writecount = ft_putnbr_base(arg, HEXA, format);
		}
		return (format.writecount = ft_print_padding_ptr(format));
	}
	format.writecount = ft_print_padding_ptr(format);
	format.writecount = ft_putptr_fd(arg, 1, format);
	if (arg != 0)
	{
		format.writecount = ft_print_precision_ptr(format, arg);
		format.writecount = ft_putnbr_base(arg, HEXA, format);
	}
	return (format.writecount);
}

int			ft_print_int(t_format format, va_list *va)
{
	int		arg;
	char	*str;

	arg = va_arg(*va, int);
	str = ft_itoa(arg);
	format = ft_set_precision_int(format, arg);
	format = ft_set_padding_int(format, arg);
	if (format.inversed)
	{
		format.writecount = ft_print_precision_int(format, arg);
		format.writecount = ft_putstr_int(str, 1, format, arg);
		format.writecount = ft_print_padding_int(format, arg);
		free(str);
		return (format.writecount);
	}
	format.writecount = ft_print_padding_int(format, arg);
	format.writecount = ft_print_precision_int(format, arg);
	format.writecount = ft_putstr_int(str, 1, format, arg);
	free(str);
	return (format.writecount);
}
