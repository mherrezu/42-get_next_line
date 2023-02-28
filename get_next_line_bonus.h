/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mherrezu <mherrezu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:28:07 by mherrezu          #+#    #+#             */
/*   Updated: 2023/02/28 12:29:56 by mherrezu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef FD_MAX
#  define FD_MAX 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

char		*get_next_line(int fd);
char		*ft_readline(int fd, char *save);
char		*join_free(char	*save, char	*buf);
char		*return_line(char	*save);
char		*freesave(char	*save);
char		*ft_strjoin(char *save, char *buf);
char		*ft_strchr(char *str, int ch);
int			ft_strlen(char *str);

#endif
