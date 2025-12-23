/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:21:37 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 21:21:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void ft_btoa(int sig)
{
    static int bit = 7;
    static unsigned char c = 0;

    if (sig == SIGUSR1)
        c |= (1 << bit);
    bit--;

    if (bit < 0)
    {
        write(1, &c, 1);
        bit = 7;
        c = 0;
    }
}


int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		struct sigaction sa;

		sa.sa_handler = ft_btoa;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = SA_RESTART;

		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);

		while (1)
			pause();
	}
	return (0);
}