/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_util_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:19:35 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/23 14:19:35 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_prefix_2(char **format, char c)
{
	if (**format == ' ')
	{
		if (c != 'd' && c != 'i' && c != 's')
			return (0);
		*format = *format + 1;
	}
	return (1);
}

static int	check_prefix(char **format, char c)
{
	if (**format == '#')
	{
		if (c != 'x' && c != 'X')
			return (0);
		*format = *format + 1;
	}
	if (**format == '+')
	{
		if (c != 'd' && c != 'i')
			return (0);
		*format = *format + 1;
	}
	if (**format == '0')
	{
		if (c != 'i' && c != 'u' && c != 'd' && c != 'x' && c != 'X')
			return (0);
		*format = *format + 1;
	}
	if (!check_prefix_2(format, c))
		return (0);
	return (1);
}

static int	valid_prefix(char *format)
{
	char	c;

	c = format[ft_strlen(format) - 1];
	if (!check_prefix(&format, c))
		return (0);
	while (ft_isdigit(*format))
		format++;
	if (*format != c)
		return (0);
	return (1);
}

int	valid_flag(char *format)
{
	if (!valid_prefix(format))
	{
		free(format);
		return (0);
	}
	return (1);
}
