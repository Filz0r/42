/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:08:38 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/18 12:20:06 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h> 

# define HEX_LOWER "0123456789abcdef" 
# define HEX_UPPER "0123456789ABCDEF" 

int		ft_printf(const char *buffer, ...);
int		ft_type_parser(const char *buffer, va_list(args));
int		ft_handle_pointer(int hex, unsigned long int nb);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int c);
int		ft_putu(unsigned int nb);
int		ft_puthex(int hex, unsigned long int nb);

#endif
