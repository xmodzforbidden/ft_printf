/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:50:26 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:27:43 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	ret;

	if (!str)
		return (ft_putbuff(1, "(null)", 6));
	count = 0;
	while (str[count])
	{
		ret = ft_putchar(str[count]);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	return (count);
}
