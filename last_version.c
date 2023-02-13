char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	if (!save)
	{
		save = (char *) malloc (BUFFER_SIZE + 1 * sizeof(char));
		if (!save)
		return(free(save), NULL);
	}
	save = ft_readline (fd, save);
	if (!save)
		return (free(save), NULL);
	printf ("FIRST SAVE: %s\n", save);
	line = return_line (save);
	printf ("LINE: %s\n", line);
	// save = freesave (save);
	// printf ("FINAL SAVE: %s\n", save);
	return (line);
}

//Read and check '\n'.
char	*ft_readline(int fd, char *save)
{
	char	*buf;
	int		rbytes;

	//printf ("WTF SAVE: %s\n", save);
	buf = (char *) malloc (BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return(free(buf), NULL);
	printf ("BUF NUEVO: %s\n", buf);
	rbytes = 1;
	while (rbytes > 0)
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		printf ("BUF BUCLE: %s\n", buf);
		save = ft_strjoin(save, buf);
		printf ("SAVE: %s\n", save);
		if (ft_strchr(save, '\n') || rbytes <= 0)
			break ;
	}
	free(buf);
	return (save);
}

//Return the complete line.
char	*return_line(char	*save)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strchr(save, '\n');
	if (tmp)
	{
		tmp = ft_substr (save, 0, (ft_strlen (save)
					- ft_strlen (tmp)) + 1);
		free (save);
		return (tmp);
	}
	save[i] = '\0';
	return (save);
}

//Restart SAVE one step after the '\n' was found || free save
char	*freesave(char	*save)
{
	char	*new_save;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (save[i] && save[i]!= '\n')
		i++;
	if (!save[i])
		return(free(save), NULL);
	new_save = (char *) malloc ((ft_strlen(save) - i + 1) * sizeof(char));
	if (!new_save)
		return(free(new_save), NULL);
	i++;
	while (save[i])
	{
		new_save[c++] = save[i++];
		//printf ("SAVE BUCLE: %s\n", save);
	}
	free(save);
	return (new_save);
}