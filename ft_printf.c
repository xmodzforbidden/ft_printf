/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:52:03 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:31:56 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = process_format(ap, format);
	va_end(ap);
	return (count);
}

int	process_format(va_list ap, const char *format)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ret = handle_specifier(ap, format[i]);
		}
		else
		{
			ret = process_character(format[i]);
		}
		if (ret == -1)
			return (-1);
		count += ret;
		i++;
	}
	return (count);
}

int	handle_specifier(va_list ap, char specifier)
{
	int	ret;

	ret = ft_parse(ap, specifier);
	return (ret);
}

int	process_character(char c)
{
	int	ret;

	ret = ft_putbuff(1, &c, 1);
	return (ret);
}
