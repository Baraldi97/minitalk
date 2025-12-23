#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

/* Inclusões básicas permitidas [cite: 98, 101, 104, 106] */
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

/* Inclusão do header da sua printf  */
# include "../printf/ft_printf.h"

/* ** No bônus, usamos siginfo_t para identificar o PID do remetente 
** e enviar o sinal de confirmação (ACK).
*/

/* Protótipos das funções do Servidor Bônus */
void	handle_signals(int sig, siginfo_t *info, void *context);


#endif