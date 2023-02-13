/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:20:22 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/10 14:26:22 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*new_save;
	char		*line;

	new_save = (void *)0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_readline(fd, save);
	printf("SAVE PRIMITIVO:%s\n", save);
	line = return_line(save);
	save = freesave(save);
	printf("SAVE FINAL:%s\n", save);
	return (line);
}

//Read and check '\n'.
char	*ft_readline(int fd, char *save)
{
	char	*buf;
	int		rbytes;

	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (free(buf), NULL);
	if (!save)
	{
		save = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (!save)
			return (free(save), NULL);
	}
	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes == 0)
			return (free(buf), save);
		save = join_free(save, buf);
		if (ft_strchr(buf, '\n'))
			return (free(buf), save);
	}
	free(buf);
	return (save);
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
	
}

// //Restart SAVE one step after the '\n' was found || free save
char	*freesave(char	*save)
{
	
	return (new_save);
}
