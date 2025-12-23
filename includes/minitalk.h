/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:51:25 by marvin            #+#    #+#             */
/*   Updated: 2025/12/22 21:51:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* Bibliotecas permitidas pelo PDF */
# include <signal.h>   /* signal, sigaction, kill [cite: 101, 104, 105] */
# include <unistd.h>   /* write, getpid, pause, sleep, usleep, fsync [cite: 99, 106, 109, 110, 111] */
# include <stdlib.h>   /* malloc, free, exit [cite: 107, 108, 112] */
# include <stdarg.h>   /* Se sua ft_printf usar variadic functions */

/* ** Se você estiver usando sua libft codificada,
** pode incluir o header dela aqui[cite: 94, 100].
*/

/* --- Parte Mandatória --- */

/* Server functions */
void    handle_signals(int sig);

/* Utils (Exemplos de funções que você pode ter na libft) */
int		ft_printf(const char *format, ...);

#endif