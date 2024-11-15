/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaki <azaki@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:56:41 by azaki             #+#    #+#             */
/*   Updated: 2024/11/15 05:33:33 by azaki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(long nb, int base, char *key);
int	ft_putnbr_base_unsigned(unsigned long nb, int base, char *key);
int	ft_parse(va_list ap, char c);
int	ft_putbuff(int fd, const void *buf, size_t count);
int	process_format(va_list ap, const char *format);
int	handle_specifier(va_list ap, char specifier);
int	process_character(char c);

#endif
