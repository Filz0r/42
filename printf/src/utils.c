/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:16:34 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/18 12:18:15 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_type_parser(const char *buffer, va_list(args))
{
	int	k;

	k = 0;
	if (*buffer == 'c')
		k += ft_putchar(va_arg(args, int));
	else if (*buffer == 's')
		k += ft_putstr(va_arg(args, char *));
	else if (*buffer == 'd' || *buffer == 'i')
		k += ft_putnbr(va_arg(args, int));
	else if (*buffer == '%')
		k += ft_putchar((int) '%');
	else if (*buffer == 'u')
		k += ft_putu(va_arg(args, unsigned int));
	else if (*buffer == 'x' || *buffer == 'X')
		k += ft_puthex(*buffer, va_arg(args, unsigned int));
	else if (*buffer == 'p')
		k += ft_handle_pointer(*buffer, va_arg(args, unsigned long int));
	return (k);
}

int	ft_handle_pointer(int hex, unsigned long int nb)
{
	int	k;

	k = 0;
	if (nb)
	{
		k += ft_putstr("0x");
		k += ft_puthex(hex, nb);
	}
	else
		k += ft_putstr("(nil)");
	return (k);
}
