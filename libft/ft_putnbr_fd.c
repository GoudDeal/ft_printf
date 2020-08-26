/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:17:10 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:29:38 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int nb, int fd, t_format format)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		format.writecount = ft_putchar_fd('-', fd, format);
	}
	if (n > 9)
	{
		format.writecount = ft_putnbr_fd(n / 10, fd, format);
		format.writecount = ft_putnbr_fd(n % 10, fd, format);
	}
	else
		format.writecount = ft_putchar_fd(n + '0', fd, format);
	return (format.writecount);
}

int		ft_putnbr_base(long int nb, char *base, t_format format)
{
	unsigned int	arg_unsigned;

	if (nb < 0 && (format.type == 'p' || format.type == 'x'
				|| format.type == 'X'))
	{
		arg_unsigned = nb;
		if (arg_unsigned > 15)
		{
			format.writecount = ft_putnbr_base(arg_unsigned / 16, base, format);
			format.writecount = ft_putnbr_base(arg_unsigned % 16, base, format);
		}
		else
			format.writecount = ft_putchar_fd(base[arg_unsigned], 1, format);
		return (format.writecount);
	}
	if (format.int_zero)
		return (format.writecount);
	if (nb > 15)
	{
		format.writecount = ft_putnbr_base(nb / 16, base, format);
		format.writecount = ft_putnbr_base(nb % 16, base, format);
	}
	else
		format.writecount = ft_putchar_fd(base[nb], 1, format);
	return (format.writecount);
}

int		ft_putnbr_unsigned(long int nb, t_format format)
{
	unsigned int	n;

	n = nb;
	if (n > 9)
	{
		format.writecount = ft_putnbr_fd(n / 10, 1, format);
		format.writecount = ft_putnbr_fd(n % 10, 1, format);
	}
	else
		format.writecount = ft_putchar_fd(n + '0', 1, format);
	return (format.writecount);
}
