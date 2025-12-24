/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta <rcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 17:50:39 by rcosta            #+#    #+#             */
/*   Updated: 2025/12/23 17:50:39 by rcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile sig_atomic_t	g_received = 0;

static void	handle_ack(int sig)
{
	(void)sig;
	g_received = 1;
}

static void	ft_atob(int pid, char c)
{
	int	bit;
	int	timeout;

	bit = 0;
	while (bit < 8)
	{
		g_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		
		timeout = 0;
		while (!g_received)
		{
			if (timeout == 50)
			{
				write(1, "Error: Server timeout\n", 22);
				exit(1);
			}
			timeout++;
			usleep(100000);
		}
		bit++;
	}
}

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

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(1, "Usage: ./client [PID] [STRING]\n", 32);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	
	signal(SIGUSR1, handle_ack);
	
	i = 0;
	while (argv[2][i])
	{
		ft_atob(pid, argv[2][i]);
		i++;
	}
	ft_atob(pid, '\n');
	return (0);
}