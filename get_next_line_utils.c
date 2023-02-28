/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:05 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/28 19:00:47 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// STRJOIN: Reserva (con malloc(3)) y devuelve una nueva string, formada por la 
// concatenación de ’s1’ y ’s2’.
char	*ft_strjoin(char *save, char *buf)
{
	char	*s3;
	int		len_s1;
	int		len_s2;
	int		i;

	len_s1 = ft_strlen(save);
	len_s2 = ft_strlen(buf);
	s3 = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!s3)
		return (free(s3), NULL);
	i = 0;
	while (i < len_s1)
	{
		s3[i] = save[i];
		i++;
	}
	i = 0;
	while (i <= len_s2)
	{
		s3[len_s1 + i] = buf[i];
		i++;
	}
	return (s3);
}

//locates the first occurrence of c (converted to a char) in the string pointed
//to by s.  The terminating null character is considered to be part of the
//string; therefore if c is `\0', the functions locate the terminating `\0'.
char	*ft_strchr(char *str, int ch)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\0')
	{
		if (str[i] == (char)ch)
			return (&str[i]);
		i++;
	}
	if ((char)ch == '\0')
		return (&str[i]);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
