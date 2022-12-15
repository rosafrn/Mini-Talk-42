/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:45:21 by rosferna          #+#    #+#             */
/*   Updated: 2022/12/15 14:31:06 by rosferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (send(argv[1], (unsigned char *)argv[2]))
		return (1);
	return (0);
}

int	send(char *server_pid, unsigned char *str)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = ft_atoi(server_pid);
	if (pid <= 0)
	{
		write(1, "Enter a valid PID\n", 18);
		return (1);
	}
	while (str[i] != '\0')
	{
		if (encode(str[i], pid) == 1)
		{
			write(1, "Clound't send signal\n", 21);
			return (1);
		}
		i++;
	}
	send_null(pid); 
	return (0);
}

int	encode(unsigned char i, pid_t pid)
{
	int	x;

	x = 7;
	while (x >= 0)
	{
		if ((i >> x) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (1);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				return (1);
		}
		usleep(100);
		x--;
	}
	return (0);
}

int send_null(pid_t pid)
{
	int	i;
	
	i = 0;
	while (i < 8)
	{
		if (kill(pid, SIGUSR1) == -1)
				return (1);
		i++;
	}
	return (0);
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
