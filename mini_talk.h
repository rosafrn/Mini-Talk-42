/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:39:34 by rosferna          #+#    #+#             */
/*   Updated: 2022/10/28 21:41:31 by rosferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	client(char *server_pid, unsigned char *str);
void	send_encode(int i, pid_t pid);
void	handle_signals(int sig);
void	print_pid(void);
int		countdigits(long n);
char	*ft_itoa(int n);
#endif