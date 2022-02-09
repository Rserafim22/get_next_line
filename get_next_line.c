/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserafim <rserafim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:02:08 by rserafim          #+#    #+#             */
/*   Updated: 2022/02/09 12:31:37 by rserafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"

static void free_ptr(char **ptr)
{
    if (*ptr != NULL)
    {
        free (*ptr);
        *ptr = NULL;
    }
}

static char	*ft_return_line(char **save, char *res)
{
    int     i;
    char    *tmp;

    i = 0;
    tmp = NULL;
    while ((*save)[i] != '\n' && (*save)[i])
        i++;
    if ((*save)[i++] == '\n')
        res = ft_substr(*save, 0, i);
    else if (ft_strchr(*save, '\0')) /*voir si c'est la fin du fichier*/
    {
        if (**save == '\0')
        {
            free_ptr(save);
            return (NULL);
        }
        res = *save;
        *save = NULL;
        return (res);
    }
    tmp = ft_strdup(*save + i);
    free(*save);
    *save = tmp;
    return (res);
}

static char *ft_read_file(int fd, char **save, char *buf)
{
    int     file;
    char    *tmp;
    char    *res;

    res = NULL;
    file = read(fd, buf, BUFFER_SIZE);
    while (file)
    {
        buf[file] = '\0';
        tmp = ft_strjoin(*save, buf);
        free(*save);
        *save = ft_strdup(tmp);
        free_ptr(&tmp);
        if (ft_strchr(buf, '\n'))
            break;
        file = read(fd, buf, BUFFER_SIZE);
    }
    free_ptr (&buf);
    return (ft_return_line(save, res));
    
}
char    *get_next_line(int fd)
{
    static char *save;
    char        *buf;
    char        *ret;
    
    buf = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
        return (NULL);
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    if (!save)
        save = ft_strdup("");
    ret = ft_read_file(fd, &save, buf);
    if (ret == NULL)
        free_ptr(&save);
    return (ret);
}