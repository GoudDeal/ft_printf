/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:06:18 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:32:57 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_print_padding_int(t_format format, int arg)
{
	(void)arg;
	if (format.inversed == 0)
	{
		if (format.fill == '0' && arg < 0)
			format.writecount = ft_putchar_fd('-', 1, format);
		while (format.padding > 0)
		{
			format.writecount = ft_putchar_fd(format.fill, 1, format);
			format.padding--;
		}
		if (arg < 0 && format.fill == ' ')
			format.writecount = ft_putchar_fd('-', 1, format);
		return (format.writecount);
	}
	while (format.padding > 0)
	{
		format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.padding--;
	}
	return (format.writecount);
}

int			ft_print_padding_str(t_format format, char *arg)
{
	(void)arg;
	while (format.padding > 0)
	{
		format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.padding--;
	}
	return (format.writecount);
}

int			ft_print_padding_char(t_format format)
{
	while ((format.width - 1) > 0)
	{
		format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.width--;
	}
	return (format.writecount);
}

int			ft_print_padding_ptr(t_format format)
{
	while (format.padding > 0)
	{
		format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.padding--;
	}
	return (format.writecount);
}

int			ft_print_padding_null(t_format format)
{
	while (format.padding > 0)
	{
		format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.padding--;
	}
	return (format.writecount);
}
