/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:51:13 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:30:52 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_int_min_case(void)
{
	int	ret;
	int	count;

	count = 0;
	ret = ft_putbuff(1, "-", 1);
	if (ret == -1)
		return (-1);
	count += ret;
	ret = ft_putbuff(1, "2147483648", 10);
	if (ret == -1)
		return (-1);
	return (count + ret);
}

static int	ft_putnbr_base_negative(long *nb, int *count)
{
	int	ret;

	if (*nb < 0)
	{
		*nb = -(*nb);
		ret = ft_putbuff(1, "-", 1);
		if (ret == -1)
			return (-1);
		*count += ret;
	}
	return (0);
}

static int	ft_putnbr_base_recursive(long nb, int base, char *key, int *count)
{
	int	ret;

	if (nb >= base)
	{
		ret = ft_putnbr_base(nb / base, base, key);
		if (ret == -1)
			return (-1);
		*count += ret;
	}
	ret = ft_putbuff(1, &key[nb % base], 1);
	if (ret == -1)
		return (-1);
	*count += ret;
	return (0);
}

int	ft_putnbr_base(long nb, int base, char *key)
{
	int	count;
	int	ret;

	count = 0;
	if (nb == INT_MIN)
		return (ft_putnbr_base_int_min_case());
	if (nb == 0)
		return (ft_putbuff(1, "0", 1));
	if (!key)
		key = "0123456789abcdef";
	ret = ft_putnbr_base_negative(&nb, &count);
	if (ret == -1)
		return (-1);
	ret = ft_putnbr_base_recursive(nb, base, key, &count);
	if (ret == -1)
		return (-1);
	return (count);
}
