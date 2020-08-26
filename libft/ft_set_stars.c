/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 17:30:23 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:27:38 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_format	ft_set_stars(t_format format, va_list *va)
{
	if (format.width_star)
		format.width = va_arg(*va, int);
	if (format.width < 0)
	{
		format.inversed = 1;
		format.fill = ' ';
	}
	format.width = format.width < 0 ? format.width * (-1) : format.width;
	if (format.precision_star)
		format.min = va_arg(*va, int);
	if (format.min < 0 && (format.type == 'd' || format.type == 'i'))
		format.precision_default = 1;
	else if (format.min == -1 && (format.type == 'd' || format.type == 'i'))
		format.min *= (-1);
	return (format);
}
