/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:28:28 by imorina           #+#    #+#             */
/*   Updated: 2021/11/29 14:47:35 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	unsigned int	nbr;

	len = ft_intlen(n);
	s = ft_calloc(len + 1, 1);
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		nbr = n * -1;
		s[0] = '-';
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		s[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (s);
}
