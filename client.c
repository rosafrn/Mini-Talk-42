/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:45:21 by rosferna          #+#    #+#             */
/*   Updated: 2022/10/28 21:57:20 by rosferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	client(argv[1], (unsigned char *)argv[2]);
}

void	client(char *server_pid, unsigned char *str)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = atoi(server_pid);
	while (str[i] != '\0')
	{
		send_encode(str[i], pid);
		i++;
	}
}

void	send_encode(int i, pid_t pid)
{
	int	x;

	x = 7;
	while (x >= 0)
	{
		if ((i >> x) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(30);
		x--;
	}
}
