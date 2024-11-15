/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 03:49:03 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:19:40 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbuff(int fd, const void *buf, size_t count)
{
	ssize_t	ret;

	ret = write(fd, buf, count);
	return (ret);
}
