/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azghibat <azghibat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:52:06 by azghibat          #+#    #+#             */
/*   Updated: 2024/12/10 10:32:38 by azghibat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lencounter(unsigned long num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

char	*ft_convert_tohex(unsigned int num, int upper)
{
	char	*my_hexa;
	char	*result;
	int		len;

	if (upper)
		my_hexa = "0123456789ABCDEF";
	else
		my_hexa = "0123456789abcdef";
	len = ft_lencounter(num);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[--len] = my_hexa[num % 16];
		num /= 16;
	}
	return (result);
}

char	*ft_convert_ptr(void *ptr)
{
	unsigned long	adr;
	int				len;
	char			*hex;
	char			*result;

	hex = "0123456789abcdef";
	adr = (unsigned long)ptr;
	len = ft_lencounter(adr);
	result = malloc(sizeof(char) * (len + 3));
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = 'x';
	result[len + 2] = '\0';
	if (!adr)
		return (result[2] = '0', result);
	while (adr)
	{
		result[len + 1] = hex[adr % 16];
		adr /= 16;
		len--;
	}
	return (result);
}

int	handle_perc()
{
	ft_putchar('%');
	return (1);
}
