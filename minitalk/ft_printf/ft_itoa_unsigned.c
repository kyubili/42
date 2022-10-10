/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigneddec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:31:32 by imorina           #+#    #+#             */
/*   Updated: 2021/12/20 22:34:42 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

void	ft_itoa_unsigned(unsigned int nbr, int *count)
{
	char	*num;
	int		len;

	len = ft_num_len(nbr);
	num = (char *) malloc(len + 1 * sizeof(char));
	if (!num)
		return ;
	num[len] = '\0';
	len--;
	if (nbr == 0)
		ft_print_char('0', count);
	else
	{
		while (nbr > 0)
		{
			num[len] = nbr % 10 + '0';
			nbr /= 10;
			len--;
		}
	}
	ft_print_str(num, count);
	free(num);
}

/*int	main(void)
{
	int	i;

	i = 0;
	ft_itoa_unsigned(789, &i);
	return (0);
}*/

/*void	ft_print_unsigneddec(unsigned int nbr, int *count)
{
	char	*str;

	str = ft_itoa_unsigned(nbr);
	count += ft_strlen(str);
	free(str);
}*/
