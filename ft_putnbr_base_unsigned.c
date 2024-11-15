/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:51:31 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:21:05 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_unsigned(unsigned long nb, int base, char *key)
{
	int	count;
	int	ret;

	count = 0;
	if (nb == 0)
		return (ft_putbuff(1, "0", 1));
	if (!key)
		key = "0123456789abcdef";
	if (nb >= (unsigned long)base)
	{
		ret = ft_putnbr_base_unsigned(nb / base, base, key);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putbuff(1, &key[nb % base], 1);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
