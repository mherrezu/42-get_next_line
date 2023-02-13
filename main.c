/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:39:27 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/08 18:31:53 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		close(int fd);
char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	printf("LINE 1: %s\n", line);
	line = get_next_line(fd);
	printf("LINE 2: %s\n", line);
	line = get_next_line(fd);
	printf("LINE 3: %s\n", line);
	// line = get_next_line(fd);
	// printf("LINE 4: %s\n", line);
	// line = get_next_line(fd);
	// printf("LINE 5: %s\n", line);
	// line = get_next_line(fd);
	// printf("LINE 6: %s\n", line);
	close(fd);
}
