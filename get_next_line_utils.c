#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	i;
	size_t	len;

	len = 0;
	if (s1 != NULL)
		len = ft_strlen(s1);
	if (s2 != NULL)
		len += ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (s1 && s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2 && s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!*str && !c)
		return((char *)str);
	return (NULL);
}

char	*ft_sort(char *buf, int *ret)
{
	int	i;
	char	*dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(char) *(i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (ft_strchr(buf, '\n') != 0)
		*ret = 1;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_sort2(char *buf)
{
	int	i;
	int	j;
	char	*dest;

	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (buf && buf[i])
		dest[j++] = buf[++i];
	dest[j] = '\0';
	return (dest);
}
