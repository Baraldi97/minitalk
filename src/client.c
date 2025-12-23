/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:59:58 by marvin            #+#    #+#             */
/*   Updated: 2025/12/22 08:49:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static volatile sig_atomic_t	g_received = 0;

static int	ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned int long		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	handle_ack(int sig)
{
	(void)sig;
	g_received = 1;
}

void	ft_atob(int pid, char c)
{
	int	bit;
	int	timeout;

	bit = 0;
	while (bit < 8)
	{
		g_received = 0;
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		timeout = 0;
		while (!g_received && timeout < 1000)
		{
			usleep(100);
			timeout++;
		}
		if (timeout >= 1000)
		{
			ft_printf("Timeout waiting for Signal\n");
			exit(1);
		}
		bit++;
	}
}


int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR1, handle_ack);
		while (argv[2][i] != '\0')
		{
			ft_atob(pid, argv[2][i]);
			i++;
		}
		ft_atob(pid, '\n');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
