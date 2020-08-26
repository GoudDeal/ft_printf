/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:07:21 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:27:52 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char *s, int fd, t_format format)
{
	int	i;

	(void)fd;
	i = 0;
	if (format.precision == 1)
	{
		while (format.prec_size > 0 && s[i])
		{
			format.writecount = ft_putchar_fd(s[i], 1, format);
			format.prec_size--;
			i++;
		}
		return (format.writecount);
	}
	else
	{
		while (s[i])
		{
			format.writecount = ft_putchar_fd(s[i], 1, format);
			i++;
		}
	}
	return (format.writecount);
}

int		ft_putstr_int(char *s, int fd, t_format format, int arg)
{
	int	i;

	(void)fd;
	i = 0;
	if (arg < 0)
		i++;
	if (format.precision)
	{
		if (format.int_zero)
			return (format.writecount);
		while (s[i])
			format.writecount = ft_putchar_fd(s[i++], 1, format);
		return (format.writecount);
	}
	while (s[i])
		format.writecount = ft_putchar_fd(s[i++], 1, format);
	return (format.writecount);
}

int		ft_putstr_unsigned(char *s, int fd, t_format format, unsigned int arg)
{
	int	i;

	(void)fd;
	(void)arg;
	i = 0;
	if (format.precision)
	{
		if (format.int_zero)
			return (format.writecount);
		while (format.prec_size > 0)
		{
			format.writecount = ft_putchar_fd('0', 1, format);
			format.prec_size--;
		}
		while (s[i])
			format.writecount = ft_putchar_fd(s[i++], 1, format);
		return (format.writecount);
	}
	while (s[i])
		format.writecount = ft_putchar_fd(s[i++], 1, format);
	return (format.writecount);
}

int		ft_putptr_fd(long int arg, int fd, t_format format)
{
	(void)fd;
	if (arg == 0)
		return (format.writecount = ft_putstr_fd("0x0", 1, format));
	format.writecount = ft_putchar_fd('0', 1, format);
	format.writecount = ft_putchar_fd('x', 1, format);
	if (arg < 0)
		format.writecount = ft_putstr_fd("ffffffff", 1, format);
	return (format.writecount);
}
