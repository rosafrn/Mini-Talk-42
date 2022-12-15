/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosferna <rosferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 21:39:34 by rosferna          #+#    #+#             */
/*   Updated: 2022/12/15 14:18:09 by rosferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int	send(char *server_pid, unsigned char *str);
int	encode(unsigned char i, pid_t pid);
void	handle_signals(int signum, siginfo_t *info, void *context);
void	print_pid(void);
int		countdigits(long n);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
size_t	ft_strlcat(char *dst, const char src, size_t dstsize);
int send_null(pid_t pid);
#endif