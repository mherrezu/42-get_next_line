/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:05 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/10 14:27:26 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// STRJOIN: Reserva (con malloc(3)) y devuelve una nueva string, formada por la 
// concatenación de ’s1’ y ’s2’.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	len;

	if (!s1 && !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s3 = (char *) malloc (len * sizeof (char));
	if (!s3)
		return (0);
	if (s1 && s2)
	{
		i = ft_strlen(s1);
		ft_strlcpy(s3, s1, i + 1);
		ft_strlcpy(&s3[i], s2, (ft_strlen(s2) + 1));
	}
	return (s3);
}

//locates the first occurrence of c (converted to a char) in the string pointed
//to by s.  The terminating null character is considered to be part of the
//string; therefore if c is `\0', the functions locate the terminating `\0'.
char	*ft_strchr(const char *str, int ch)
{
	char	*s;

	s = (char *)str;
	while (*s != '\0')
	{
		if (*s == (unsigned char)ch)
			return (s);
		s++;
	}
	if ((unsigned char)ch == '\0')
		return (s);
	return (0);
}

// Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
// La substring empieza desde el índice ’start’ y tiene una longitud máxima len.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	leng;

	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		leng = ft_strlen(s) - start;
	else
		leng = len;
	subs = (char *) malloc ((leng + 1) * sizeof (char));
	if (!subs)
	{
		free (subs);
		return (NULL);
	}
	while (i < leng)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	return (subs);
}

// allocates sufficient memory for a copy of the string src, does the copy, and 
// returns a pointer to it.  The pointer may subsequently be used as an argument
// to the function free(3).

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		s_size;
	int		i;

	i = 0;
	dst = NULL;
	s_size = (ft_strlen(src) + 1);
	dst = (char *) malloc (s_size * sizeof (char));
	if (!dst)
	{
		free (dst);
		return (NULL);
	}
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

//strlcpy() copies up to dstsize - 1 characters from the string src to dst,
//NUL-terminating the result if dstsize is not 0.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	c;

	c = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while ((c < (dstsize - 1)) && (src[c] != '\0'))
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
