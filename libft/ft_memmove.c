/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:51:35 by imorina           #+#    #+#             */
/*   Updated: 2021/11/29 14:31:04 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;

	source = src;
	destination = dst;
	if (source >= destination)
		ft_memcpy(destination, source, len);
	else
	{
		source += len;
		destination += len;
		while (len--)
			*--destination = *--source;
	}
	return (dst);
}
