/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rserafim <rserafim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:02:19 by rserafim          #+#    #+#             */
/*   Updated: 2022/02/09 10:47:40 by rserafim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# ifndef     BUFFER_SIZE
# define    BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

size_t  ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char    *ft_strdup(char *s1);
char    *ft_substr(const char *str, unsigned int start, size_t len);
char    *get_next_line(int fd);

#endif
