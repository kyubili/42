/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:31:22 by imorina           #+#    #+#             */
/*   Updated: 2021/12/20 22:00:51 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
		ft_print_str("(null)", count);
	else
	{
		while (str[i])
		{
			ft_print_char(str[i], count);
			i++;
		}
	}
}
