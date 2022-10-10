/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:49:43 by imorina           #+#    #+#             */
/*   Updated: 2021/11/29 14:46:30 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char));
	if (str == 0)
		return (NULL);
	while (*s1 != 0)
	{
		str[i++] = *s1++;
	}	
	while (*s2)
	{
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}
