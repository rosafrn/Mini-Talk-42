/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:39:34 by rosferna          #+#    #+#             */
/*   Updated: 2022/11/09 22:24:42 by rosferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	client(char *server_pid, unsigned char *str);
void	send_encode(unsigned char i, pid_t pid);
void	handle_signals(int sig);
void	print_pid(void);
int		countdigits(long n);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
#endif