/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:45:21 by rosferna          #+#    #+#             */
/*   Updated: 2022/10/28 22:13:10 by rosferna         ###   ########.fr       */
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
	pid = ft_atoi(server_pid);
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

int	ft_atoi(const char *str)
{
	int			sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (*str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		nbr = nbr * 10;
		nbr += (sign * (*(str++) - 48));
		if (nbr > 2147483647)
			return (-1);
		if (nbr < -2147483648)
			return (0);
	}
	return (nbr);
}
