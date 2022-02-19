/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:31:34 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 02:31:34 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:50:20 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 01:50:20 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	null_char(int *i)
{
	char	*str;

	*i = *i + 1;
	str = (char *)malloc(sizeof(char) * 1);
	if (str)
		str[0] = '\0';
	return (str);
}

char	*get_char(va_list *arg, int *i)
{
	int	c;
	char	*str;

	c = va_arg(*arg, int);
	if (c == 0)
		return (null_char(i));
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = (unsigned char)c;
	str[1] = '\0';
	return (str);
}

static char	*null_str(void)
{
	char	*null;
	char	*str;

	null = "(null)";
	str = (char *)malloc(sizeof(char) * 7);
	if (str)
		ft_strlcpy(str, null, 7);
	return (str);
}

char	*get_str(va_list *arg)
{
	char	*s;
	char	*str;
	size_t	len;

	s = va_arg(*arg, char *);
	if (!s)
		return (null_str());
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	*get_dec(va_list *arg)
{
	int	i;
	char	*str;

	i = va_arg(*arg, int);
	str = ft_itoa(i);
	return (str);
}
