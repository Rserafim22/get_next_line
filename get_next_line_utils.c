/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserafim <rserafim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:07:59 by rserafim          #+#    #+#             */
/*   Updated: 2022/02/09 12:53:12 by rserafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str) + 1)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	int		len;
	int		i;
	char	*str;

	i = -1;
	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*s;

	i = -1;
	if (!str)
		return (NULL);
	if (len > ft_strlen(str))
		len = ft_strlen(str);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	while (++i < len && start < ft_strlen(str))
		s[i] = str[start++];
	s[i] = '\0';
	return (s);
}
