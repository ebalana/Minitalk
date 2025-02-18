/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalana- <ebalana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:49:43 by ebalana-          #+#    #+#             */
/*   Updated: 2025/02/18 13:28:37 by ebalana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_ack_received = 0;

void	wait_for_ack(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

void	send_char(pid_t pid, char c)
{
	int					i;
	struct sigaction	sa;

	sa.sa_handler = wait_for_ack;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack_received)
			pause();
		i--;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("Format: %s <PID> \"<mensaje>\"\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, '\0');
	ft_printf("Message sent successfully!\n");
	return (0);
}
