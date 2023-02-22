/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:20:22 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/22 12:38:08 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*save[INT_MAX];
	char		*line;

	if (!save[fd])
		save[fd] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = ft_readline(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = return_line(save[fd]);
	save[fd] = freesave(save[fd]);
	return (line);
}

//Read and check '\n'. It's necessary to check rbytes & save to avoid 
// memory leaks
char	*ft_readline(int fd, char *save)
{
	char	*buf;
	int		rbytes;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(buf), NULL);
	rbytes = 2;
	while (!ft_strchr(save, '\n') && rbytes > 0)
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes == -1)
			return (free(buf), free(save), NULL);
		buf[rbytes] = 0;
		save = join_free(save, buf);
	}
	return (free(buf), save);
}

//Join the read buf our static variable save into a new variable, 
//and then freeing the save. It's because we can't overwrite a variable
// with itself.
char	*join_free(char	*save, char	*buf)
{
	char	*aux;

	aux = ft_strjoin(save, buf);
	free (save);
	return (aux);
}

//Return the complete line. Taking into account emepty file, end of file &
// '\n' lines
char	*return_line(char	*save)
{
	char	*line;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (free(line), NULL);
	while (c <= i)
	{
		line[c] = save[c];
		c++;
	}
	if (save[i] && save[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

// //Restart SAVE one step after the '\n' was found || free save
char	*freesave(char	*save)
{
	char	*new_save;
	int		i;
	int		c;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (!save[i])
		return (free(save), NULL);
	c = ft_strlen(save) - i + 1;
	new_save = (char *)malloc(c * sizeof(char));
	if (!new_save)
		return (free(new_save), NULL);
	i = i + 1;
	c = 0;
	while (save[i] != '\0')
		new_save[c++] = save[i++];
	new_save[c] = '\0';
	return (free(save), new_save);
}
