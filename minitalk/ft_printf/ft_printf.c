/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:30:43 by imorina           #+#    #+#             */
/*   Updated: 2021/12/21 17:15:09 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_type(const char format, va_list args, int *count)
{
	if (format == 'c')
		ft_print_char(va_arg(args, int), count);
	else if (format == 's')
		ft_print_str(va_arg(args, char *), count);
	else if (format == 'p')
		ft_print_ptr(va_arg(args, unsigned long int), count);
	else if (format == 'd' || format == 'i')
		ft_print_int(va_arg(args, int), count);
	else if (format == 'u')
		ft_itoa_unsigned(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_print_hex(va_arg(args, int), count, 0);
	else if (format == 'X')
		ft_print_hex(va_arg(args, int), count, 1);
	else if (format == '%')
		ft_print_char('%', count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!input)
		return (0);
	i = 0;
	count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] != '%')
			ft_print_char(input[i], &count);
		else if (input[i] == '%' && input[i + 1])
			check_type(input[++i], args, &count);
		i++;
	}
	va_end(args);
	return (count);
}

/*int	main(void)
{
	printf("\nVALUE : %p:\n", );
	printf("\nVALUE : %d:\n", ft_printf("%p", "Y"));
   return (0);	
}*/

/*int main()
{
	const char	*text;
	const char	*lettre;
	int			nombre;
	int			nombre2;
	unsigned int			nombre3;
	int			nombre4;
	int	printfc;
	void *ptr;
	text = "ft_tagueule";
	lettre = "c";
	nombre = 42424242;
	nombre2 = 43;
	nombre3 = 42;
	nombre4 = -1;
	printfc = 0;
	ptr = &nombre;
	printf("\n\n------------------------------\nx: \n");
	ft_printf("Result = %x\n", nombre);
	printf("Result = %x\n\n", nombre);
	printf("------------------------------\nX: \n");
	ft_printf("Result = %X\n", nombre);
	printf("Result = %X\n\n", nombre);
	printf("------------------------------\np: \n");
	ft_printf("Result = %p\n", ptr);
	printf("Result = %p\n\n", ptr);
	printf("------------------------------\n\n");
	//printf("N lettre: %d\n", count);
	//printf("Printf: %d\n", printfc);
	//	printf("Real: %x + %X", nombre3, nombre3);
}*/
