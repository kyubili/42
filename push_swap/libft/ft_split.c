/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:44:33 by imorina           #+#    #+#             */
/*   Updated: 2021/11/29 14:41:31 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			words++;
		}
		else
			i++;
	}
	return (words);
}

int	count_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**ptr;

	i = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	ptr = ft_calloc(count + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < count)
	{
		while (*s && *s == c)
		{
			s++;
		}
		ptr[i] = ft_substr((char *)s, 0, count_len((char *)s, c));
		s = s + count_len(s, c);
		i++;
	}
	ptr[count] = 0;
	return (ptr);
}
