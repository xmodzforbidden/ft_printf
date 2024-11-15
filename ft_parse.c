/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:51:54 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:29:42 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_pointer(va_list ap)
{
	int				count;
	int				ret;
	unsigned long	ptr_val;

	count = 0;
	ptr_val = (unsigned long)va_arg(ap, void *);
	ret = ft_putbuff(1, "0x", 2);
	if (ret == -1)
		return (-1);
	count += ret;
	if (ptr_val == 0)
		ret = ft_putbuff(1, "0", 1);
	else
		ret = ft_putnbr_base_unsigned(ptr_val, 16, NULL);
	if (ret == -1)
		return (-1);
	return (count + ret);
}

int	ft_parse(va_list ap, char c)
{
	int	ret;

	if (c == 'd' || c == 'i')
		ret = ft_putnbr_base(va_arg(ap, int), 10, NULL);
	else if (c == 'u')
		ret = ft_putnbr_base_unsigned(va_arg(ap, unsigned int), 10, NULL);
	else if (c == 'x')
		ret = ft_putnbr_base_unsigned(va_arg(ap, unsigned int), 16, NULL);
	else if (c == 'X')
		ret = ft_putnbr_base_unsigned(va_arg(ap, unsigned int), 16,
				"0123456789ABCDEF");
	else if (c == 'p')
		ret = ft_handle_pointer(ap);
	else if (c == 'c')
		ret = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		ret = ft_putstr(va_arg(ap, char *));
	else if (c == '%')
		ret = ft_putbuff(1, "%", 1);
	else
		ret = 0;
	if (ret == -1)
		return (-1);
	return (ret);
}
