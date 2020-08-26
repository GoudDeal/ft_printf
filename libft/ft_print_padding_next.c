/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:28:30 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:33:29 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_print_padding_unsigned(t_format format, long int arg)
{
	(void)arg;
	if (format.inversed == 0)
	{
		while (format.padding > 0)
		{
			format.writecount = ft_putchar_fd(format.fill, 1, format);
			format.padding--;
		}
		return (format.writecount);
	}
	while (format.padding > 0)
	{
		format.writecount = ft_putchar_fd(format.fill, 1, format);
		format.padding--;
	}
	return (format.writecount);
}
