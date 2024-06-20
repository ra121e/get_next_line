/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/20 12:42:44 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief returns a line extracted from text, which read by file descriptor
 */

#include "get_next_line_bonus.h"

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
			box = ft_strdup("");
		tmp = box;
		box = ft_strjoin(tmp, buf);
		free(tmp);
		if (box == NULL)
			return (NULL);
		check_newline = ft_strchr(box, '\n');
	}
	return (box);
}

char	*separate_back(char *box)
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
	return (back);
}

char	*separate_front(char *box)
{
	int		i;
	char	*front;

	i = 0;
	while (box[i] != '\n' && box[i] != '\0')
		i++;
	if (box[i] == '\n')
	{
		front = ft_substr(box, 0, i + 1);
		if (front == NULL)
			return (NULL);
	}
	else
	{
		front = ft_substr(box, 0, i);
		if (front == NULL)
			return (NULL);
	}
	return (front);
}
/**
 * @fn char	*get_next_line(int fd)
 * @brief
 * @param[in]	fd file descriptor
 */

char	*get_next_line(int fd)
{
	static char	*p[FD_SIZE];
	char		*str;
	char		*line;

	str = NULL;
	str = read_file(fd, p[fd]);
	if (str == NULL)
	{
		if (p[fd] != NULL)
			free(p[fd]);
		p[fd] = NULL;
		return (NULL);
	}
	line = separate_front(str);
	if (line == NULL)
	{
		if (str != NULL)
			free(str);
		str = NULL;
		p[fd] = NULL;
		return (NULL);
	}
	p[fd] = separate_back(str);
	free(str);
	return (line);
}
