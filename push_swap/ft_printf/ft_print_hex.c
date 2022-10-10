/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:31:09 by imorina           #+#    #+#             */
/*   Updated: 2022/08/02 21:09:16 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int n, int *count, int format)
{
	char	*base;

	if (format == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n <= 15)
		ft_print_char(base[n], count);
	else if (n > 15)
	{
		ft_print_hex(n / 16, count, format);
		ft_print_hex(n % 16, count, format);
	}
}
