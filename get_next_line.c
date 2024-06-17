/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/17 19:44:52 by athonda          ###   ########.fr       */
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

char	*read_file(int fd, char *box)
{
	ssize_t	len_check;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	char	*check_newline;

	check_newline = NULL;
	while (check_newline == NULL)
	{
		len_check = read(fd, buf, BUFFER_SIZE);
		if (len_check < 0)
			return (NULL);
		if (len_check == 0)
			return (box);
		buf[len_check] = '\0';
		if (box == NULL)
		{
			box = ft_strdup("");
		//	if (box == NULL)
		//		return (NULL);
		}
		tmp = box;
		box = ft_strjoin(tmp, buf);
		free(tmp);
		//tmp = NULL;
		if (box == NULL)
			return (NULL);
		check_newline = ft_strchr(box, '\n');
	}
	return (box);
}

char	*separate_line(char *box)
{
	int		i;
	char	*back;

	i = 0;
	while (box[i] != '\n' && box[i] != '\0')
	{
		i++;
	}
	back = ft_substr(box, i + 1, ft_strlen(box) - i);
	if (back == NULL)
		return (NULL);
	if (back[0] == '\0')
	{
		free(back);
		back = NULL;
		return (NULL);
	}
	if (box[i] == '\n')
		box[i + 1] = '\0';
	return (back);
}

/**
 * @fn char	*get_next_line(int fd)
 * @brief
 * @param[in]	fd file descriptor
 */

char	*get_next_line(int fd)
{
	static char	*p;
	char		*line;

	line = NULL;
	line = read_file(fd, p);
	if (line == NULL)
	{
		if (p != NULL)
		{
			free(p);
			p = NULL;
		}
		return (NULL);
	}
	p = separate_line(line);
	return (line);
}
