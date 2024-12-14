/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:17:31 by azghibat          #+#    #+#             */
/*   Updated: 2024/12/05 01:00:21 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (write(1, str, ft_strlen(str)));
}

int	handle_digits_int(int n)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(n);
	if (!str)
		return (-1);
	len = handle_string(str);
	free(str);
	return (len);
}

int	handle_hex_upper(unsigned int num, int upper)
{
	char	*str;
	int		len;

	str = ft_convert_tohex(num, upper);
	len = handle_string(str);
	free(str);
	return (len);
}

int	handle_unsigned_int(unsigned int num)
{
	char	str[11];
	int		len;
	int		i;

	i = 10;
	str[i] = '\0';
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (num > 0)
	{
		str[--i] = num % 10 + '0';
		num /= 10;
	}
	len = handle_string(str + i);
	return (len);
}

int	handle_pointer(void *ptr)
{
	int		len;
	char	*str;

	str = ft_convert_ptr(ptr);
	len = handle_string(str);
	free(str);
	return (len);
}
