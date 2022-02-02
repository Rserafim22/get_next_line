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

	if (s1)
		len = ft_strlen(s1);
	if (s2)
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

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int		ret;
	static char	*str = NULL;
	char		*tmp;

	ret = BUFFER_SIZE;
	if (fd < 0 || fd > 1023 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		tmp = str;
		str = ft_strjoin(tmp, buf);
		free (tmp);
		if (ft_strchr(str, '\n'))
			break;
		// coucou comment vas-tu ?\nSalut
	}
	*line = ft_sort(str, &ret);
	tmp = str;
	str = ft_sort2(tmp);
	free (tmp);
	/*if (ret == 0 && (*str)[0] == 0)
	{
		free (*str); 
		*str = NULL;
	}*/
	return (ret);
}
/*
int	main()
{
	int fd = open("salut", O_RDONLY);
	char *line = NULL;
	int ret = get_next_line(fd, &line);
	int i = 10;

	while (i > 0)
	{
		printf("%s\n", line);
		printf("%d\n", get_next_line(fd, &line));
		i--;
//		ret = get_next_line(fd, &line);
	}
}*/