/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:31:41 by imorina           #+#    #+#             */
/*   Updated: 2021/12/20 22:36:33 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(int nbr, int *count)
{
	if (nbr == -2147483648)
		ft_print_str("-2147483648", count);
	else if (nbr >= 0 && nbr <= 9)
		ft_print_char(nbr + '0', count);
	else if (nbr < 0)
	{
		ft_print_char('-', count);
		ft_print_int(nbr * (-1), count);
	}
	else
	{
		ft_print_int(nbr / 10, count);
		ft_print_int(nbr % 10, count);
	}
}
