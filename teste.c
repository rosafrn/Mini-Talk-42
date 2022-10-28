#include "mini_talk.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)ft_calloc(1, (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = (char *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_memset(str, 0, size * count);
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b1;

	b1 = (unsigned char *)b;
	while (len != 0)
	{
		*b1 = (unsigned char)c;
		len--;
		b1++;
	}
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(1, size);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
	ft_strlcat(str, s2, size);
	return (str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[z] && i + z + 1 < dstsize)
	{
		dst[i + z] = src[z];
		z++;
	}
	if (i < dstsize)
		dst[i + z] = '\0';
	return (i + ft_strlen(src));
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (src[z])
		z++;
	if (dstsize > 0)
	{
		while (src[i] && (i + 1) < dstsize)
		{	
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (z);
}


size_t	ft_strlen(const char *s)
{
	unsigned long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}