/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:50:46 by imorina           #+#    #+#             */
/*   Updated: 2022/06/03 12:54:33 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
convert_bits : Grace aux operateurs bitwise on peut checker
chaque bit du chara envoyer aux SIGUSR1 et SIGUSR2
kill : La fonction kill sert a envoyer un signal
a chaque user, apres chaque signal envoye, on laisse un temps
d'attente de 50 milisecondes
kill > 0 : sert a proteger les syscall
convert_bits:0, pid
*/

void	convert_bits(char c, pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		i--;
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR1) > 0)
			{
				ft_printf("envoyer le pid du serveur\n");
				exit(2);
			}
		}
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

/*
sigmsg : Recupere chaque caractere a envoyer au
convertisseur d'octets en bits
*/

void	sigmsg(char *msg, pid_t pid)
{
	int	i;

	i = -1;
	while (msg[++i])
		convert_bits(msg[i], pid);
	convert_bits(0, pid);
	exit(0);
}

void	received(int sig)
{
	(void)sig;
	ft_printf("Le message a bien été reçu, félicitations !\n");
	exit(0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	num;
	unsigned int	neg;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

/*
PID : Le process ID sert a identifier a quel process on envoie le signal
pause() : Attend la reception du signal
*/

int	main(int ac, char **av)
{
	pid_t	pid;

	signal(SIGUSR1, &received);
	if (ac != 3)
	{
		ft_printf("Write ./client, the server's pid and your message !");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid != 0)
		sigmsg(av[2], pid);
	while (1)
		pause();
	return (0);
}
