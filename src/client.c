/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalana- <ebalana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:49:43 by ebalana-          #+#    #+#             */
/*   Updated: 2025/02/19 12:56:06 by ebalana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_signal_received = 0;

void	wait_confirmation(int signum)
{
	(void)signum;
	g_signal_received = 1;
}

int	wait_for_response(void)
{
	int	timeout;

	timeout = 0;
	while (!g_signal_received && timeout < 5)
	{
		usleep(200000);
		timeout++;
	}
	return (g_signal_received);
}

void	send_char(pid_t pid, char c)
{
	int					i;
	struct sigaction	sa;

	sa.sa_handler = wait_confirmation;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 7;
	while (i >= 0)
	{
		g_signal_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (!wait_for_response())
		{
			ft_printf(ERROR_PID);
			exit(1);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf(WRONG_FROMAT);
		return (1);
	}
	if (!ft_isdigit_str(argv[1]))
	{
		ft_printf(ERROR_PID_NUM);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
		send_char(pid, *message++);
	send_char(pid, '\0');
	ft_printf("Message sent successfully!\n");
	return (0);
}
