/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:50:11 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:26:09 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cinset(const char c, const char *set)
{
	int i;

	if (set != NULL)
	{
		i = 0;
		while (set[i])
		{
			if (c == set[i])
				return (1);
			i++;
		}
		return (0);
	}
	return (-1);
}

int		ft_isspace(const char c)
{
	return (ft_cinset(c, "\t\n\r\v\f "));
}

int		ft_atoi(const char *str)
{
	int	i;
	int	result;

	if (str != NULL)
	{
		result = 0;
		while (ft_isspace(*str))
			str++;
		i = str[0] == '-' || str[0] == '+' ? 1 : 0;
		while (str[i] && ft_isdigit(str[i]) != 0)
			result = result * 10 + (str[i++] - '0');
		return (str[0] == '-') ? result * -1 : result;
	}
	return (0);
}
