/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:51:20 by imorina           #+#    #+#             */
/*   Updated: 2022/06/03 12:51:21 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
sighandler : Reconstitution des lettres dans le bon ordre
SIGUSR1 = signal 1
SIGUSR2 = signal 0
i : index, on passe d'un caractere a l'autre de gauche a droite
bits : chaque lettre est composée de 8 bits
*/

/*
bits << 1 : on bouge de 1 bit de droite à gauche
infos->si_pid : contient le pid du process qui a emis un signal
*/

void	sighandler(int sig, siginfo_t *infos, void *param)
{
	static char	bits = 0;
	static int	i = 0;

	(void)param;
	i++;
	bits = bits << 1;
	if (sig == SIGUSR1)
		bits = bits | 1;
	if (i == 8)
	{
		if (bits == 0)
			if (kill(infos->si_pid, SIGUSR1) > 0)
				write(2, "erreur !", 8);
		ft_printf("%c", bits);
		bits = 0;
		i = 0;
	}
}

/*
Sigaction : Initialisation d'une structure de signal avec le traitement
qu'il va recevoir dans la fonction sighandler
Siginfo : Previent le sigaction que je vais lui passer une fonction
*/

int	main(void)
{
	struct sigaction	siga;

	siga.sa_sigaction = &sighandler;
	siga.sa_flags = SA_SIGINFO;
	ft_printf("\nServer PID: \033[1;36m%d\033[0m\n\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &siga, NULL);
		sigaction(SIGUSR2, &siga, NULL);
	}
	return (0);
}
