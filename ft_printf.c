/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:59:35 by azghibat          #+#    #+#             */
/*   Updated: 2024/12/10 10:32:28 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_form(const char **form, va_list args)
{
	int		printed;

	printed = 0;
	if (**form == 'c')
		printed += ft_putchar((char)va_arg(args, int));
	else if (**form == 's')
		printed += handle_string(va_arg(args, char *));
	else if (**form == 'd' || **form == 'i')
		printed += handle_digits_int(va_arg(args, int));
	else if (**form == 'x')
		printed += handle_hex_upper(va_arg(args, unsigned int), 0);
	else if (**form == 'X')
		printed += handle_hex_upper(va_arg(args, unsigned int), 1);
	else if (**form == 'u')
		printed += handle_unsigned_int(va_arg(args, unsigned int));
	else if (**form == 'p')
		printed += handle_pointer(va_arg(args, void *));
	else if (**form == '%')
		printed += handle_perc();
	else
		return (-1);
	return (printed);
}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		printed;

	if (write(1, NULL, 0) == -1)
		return (-1);
	va_start(args, form);
	printed = 0;
	while (*form)
	{
		if (*form == '%')
		{
			form++;
			if (*form == '\0')
				break ;
			printed += handle_form(&form, args);
		}
		else if (handle_form(&form, args) == -1)
		{
			ft_putchar(*form);
			printed++;
		}
		form++;
	}
	va_end(args);
	return (printed);
}
