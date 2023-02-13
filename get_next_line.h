/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:07 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/10 12:37:35 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char		*ft_readline(int fd, char *save);
char		*join_free(char	*save, char	*buf);
char		*return_line(char	*save);
char		*freesave(char	*save);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *str, int ch);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *str);

#endif
