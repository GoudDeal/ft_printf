/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:04:34 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:27:24 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_hexa(long int arg)
{
	int		n;
	long	tmp;

	tmp = arg;
	n = 0;
	if (arg == 0)
		return (1);
	while (tmp > 0)
	{
		tmp /= 16;
		n++;
	}
	return (n);
}

int		ft_size_int(int arg)
{
	int		n;
	int		size;

	n = arg;
	size = 0;
	if (n == MIN_I)
		return (10);
	if (arg == 0)
		return (1);
	if (n < 0)
		n = n * (-1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int		ft_size_uns(long int arg)
{
	unsigned int	n;
	int				size;

	n = arg;
	size = 0;
	if (arg == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}
