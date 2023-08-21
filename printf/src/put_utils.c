/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/18 12:20:33 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str)
{
	int	k;

	k = 0;
	if (!str)
		k += ft_putstr("(null)");
	else
		while (*str)
			k += ft_putchar(*str++);
	return (k);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	k;

	k = 0;
	if (nb == -2147483648)
	{
		k += ft_putchar('-');
		k += ft_putchar('2');
		k += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		k += ft_putchar('-');
		nb = -nb;
		k += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		k += ft_putnbr(nb / 10);
		k += ft_putnbr(nb % 10);
	}
	else
	{
		k += ft_putchar(nb + 48);
	}
	return (k);
}

int	ft_putu(unsigned int nb)
{
	int	k;

	k = 0;
	if (nb > 9)
	{
		k += ft_putu(nb / 10);
		k += ft_putu(nb % 10);
	}
	else
		k += ft_putchar(nb + 48);
	return (k);
}

int	ft_puthex(int hex, unsigned long int nb)
{
	int		k;

	k = 0;
	if (nb > 15)
	{
		k += ft_puthex(hex, nb / 16);
		k += ft_puthex(hex, nb % 16);
	}
	else
	{
		if (hex == 'X')
			k += ft_putchar(HEX_UPPER[nb]);
		else
			k += ft_putchar(HEX_LOWER[nb]);
	}
	return (k);
}
