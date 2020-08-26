/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:29:12 by dcyprien          #+#    #+#             */
/*   Updated: 2020/08/18 23:25:43 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isflag(const char *flag)
{
	int i;

	if (flag != NULL && flag[0] == '%')
	{
		i = 1;
		while (flag[i] && (ft_isdigit(flag[i]) || ft_cinset(flag[i], " -.*")))
			i++;
		return (ft_cinset(flag[i], TYPE));
	}
	return (0);
}

char		*ft_getflags(const char *str)
{
	int		i;

	if (str != NULL && ft_isflag(str))
	{
		i = 1;
		while (str[i])
		{
			if (ft_cinset(str[i], TYPE))
				return (ft_substr(str, 0, i + 1));
			i++;
		}
	}
	else if (str && ft_isflag(str) != 1)
	{
		i = 1;
		while (str[i++])
		{
			if (ft_isalpha(str[i]))
				return (ft_substr(str, 0, i + 1));
		}
	}
	return (NULL);
}

t_format	ft_setflags(t_format format, const char *flags, va_list *va)
{
	int		i;

	i = 1;
	while (flags[i])
	{
		if (ft_cinset(flags[i], TYPE))
			break ;
		if (flags[i] == ' ')
		{
			format.writecount = ft_putchar_fd(' ', 1, format);
			i++;
		}
		if (!format.set_width)
			format = ft_set_width(format, &flags[i]);
		if (flags[i++] == '.' && !format.set_min)
			format = ft_set_info_prec(format, &flags[i - 1]);
	}
	if (ft_cinset(flags[i], TYPE))
		format.type = flags[i];
	if (format.precision_star || format.width_star)
		format = ft_set_stars(format, va);
	return (format);
}

t_format	ft_set_info_prec(t_format format, const char *flags)
{
	int		i;

	i = 1;
	format.set_min = 1;
	format.precision = 1;
	if (flags[i] == '*')
	{
		format.precision_star = 1;
		return (format);
	}
	if (ft_isdigit(flags[i]) || flags[i] == '-')
	{
		format.min = ft_atoi(&flags[i]);
		return (format);
	}
	return (format);
}

t_format	ft_set_width(t_format format, const char *flags)
{
	int		i;

	i = 0;
	format.set_width = 1;
	if (flags[i] == '*')
		format.width_star = 1;
	if (ft_isdigit(flags[i]) && flags[i] != '0')
	{
		format.width = ft_atoi(&flags[i]);
		return (format);
	}
	while (flags[i] == '0' || flags[i] == '-')
	{
		if (flags[i] == '0')
			format.fill = '0';
		if (flags[i] == '-')
			format.inversed = 1;
		if ((flags[i++ + 1] != '0' && ft_isdigit(flags[i])) || flags[i] == '*')
			break ;
	}
	if (flags[i] == '*' && flags[i - 1] != '.')
		format.width_star = 1;
	if (ft_isdigit(flags[i]))
		format.width = ft_atoi(&flags[i]);
	return (format);
}
