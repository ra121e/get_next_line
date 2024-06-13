/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/13 22:39:04 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief write a function that returns a line read from a file descriptor
 */

#include "get_next_line.h"

/**
 * @fn char	*get_next_line(int fd)
 * @brief
 * @param[in]	fd file descriptor
 */

int	read_file(int fd, char **box)
{
	ssize_t	len;
	ssize_t len_check;
	char	buf[BUFFER_SIZE + 1];
	char	*new;
	char	*pos_newline;

	len = 0;
	pos_newline = NULL;
	while (pos_newline == NULL)
	{
		len_check = read(fd, buf, 1);
		if (len_check < 0)
			return (-1);
		if (len_check == 0)
			return (0);
		buf[len_check] = '\0';
		len = len + len_check;
		new = ft_strjoin(*box, buf);
		free(*box);
		pos_newline = ft_strchr(new, '\n');
		*box = new;
	}

	//*box = pos_newline;
	return (len);
}

char	*make_line(char *box)
{
	int	i;
	char	*line;

	i = 0;
	while (box[i] != '\n' && box[i] != '\0')
	{
		i++;
	}
	line = ft_substr(box, 0, i);
	return (line);
}

/**
 * @fn char	*get_next_line(int fd)
 * @brief
 * @param[in]	fd file descriptor
 */

char	*get_next_line(int fd)
{
	char	*p;
	ssize_t		len;
	char	*line;

	line = NULL;
	p = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (p == NULL)
		return (NULL);
	ft_bzero(p, BUFFER_SIZE + 1);
	len = read_file(fd, &p);
	if (len == -1 || len == 0)
		return (NULL);
	p[len - 1] = '\0';
	line = make_line(p);
	return (line);
}
