/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:25:54 by imorina           #+#    #+#             */
/*   Updated: 2021/12/21 17:14:20 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_long(unsigned long int n, int *count, int format)
{
	char	*base;

	if (format == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 0 && n <= 15)
		ft_print_char(base[n], count);
	else if (n > 15)
	{
		ft_print_hex_long(n / 16, count, format);
		ft_print_hex_long(n % 16, count, format);
	}
}
