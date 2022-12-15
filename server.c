/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:45:18 by rosferna          #+#    #+#             */
/*   Updated: 2022/12/15 14:31:52 by rosferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <ctype.h>

int	main(void)
{
	struct sigaction	sa;
	sigset_t			locker;

	sigemptyset(&locker);
	sigaddset(&locker, SIGUSR1);
	sigaddset(&locker, SIGUSR2);
	sa.sa_mask = locker;
	sa.sa_sigaction = &handle_signals;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_pid();
	while (1)
		pause ();
	return (0);
}

void	print_pid(void)
{
	char	*c;
	int		i;
	pid_t	pid;

	i = 0;
	pid = getpid();
	if (pid == -1)
		return ;
	c = ft_itoa(pid);
	write(1, "PID: ", 5);
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	free (c);
	write(1, "\n", 1);
}

//this is the function I'm working on
void	handle_signals(int sig, siginfo_t *info, void *context)
{
	static int		i = 0;
	static int		letter = 0;
	static pid_t	client_pid;
	static int 		x = 0;

	if (x == 0)
	{
		client_pid = info->si_pid;
	}
	x = 1;
	(void)context;
	if (info->si_pid == client_pid)
	{
		letter *= 2;
		if (sig == SIGUSR2)
			letter += 1;
		else
			letter += 0;
		i++;
		if (i == 8)
		{
			if (letter == 0)
			{
				x = 0;
			}
			else 
				write(1, &letter, 1);
			letter = 0;
			i = 0;
		}
	}
	else
	{
		write(1, "\nUndifined Behaviour. Bit loss. Quit.", 38);
		letter = 0;
		i = 0;
		error = 1;
	}
}


int	countdigits(long n)
{
	int	d;

	if (n < 0)
		d = 1;
	else
		d = 0;
	while (1)
	{
		n = n / 10;
		d++;
		if (n == 0)
			break ;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	int		d;
	long	nn;
	char	*ret;

	nn = (long)n;
	d = countdigits(nn);
	ret = malloc((d + 1) * sizeof(char));
	if (!ret)
		return (0);
	if (nn < 0)
	{
		ret[0] = '-';
		nn = nn * -1;
	}
	ret[d] = '\0';
	while (1)
	{
		ret[d - 1] = nn % 10 + '0';
		nn = nn / 10;
		d--;
		if (nn == 0)
			break ;
	}
	return (ret);
}
