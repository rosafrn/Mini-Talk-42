#ifndef MINI_TALK_H
#define MINI_TALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void client(char *server_pid, unsigned char *str);
void    send_encode(int i, pid_t pid);
void handle_signals();
void handle_SIGUSR(int sig);
void print_decode();

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

 #endif