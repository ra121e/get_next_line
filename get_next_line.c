/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/07/02 21:40:26 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_next_line.c
 * @brief returns a line extracted from text, which read by file descriptor
 */

#include "get_next_line.h"

/**
 * @fn char	*read_file(int fd, char *box)
 * @brief
 * @param[in]	fd file descriptor
 * @param[in,out] box rest of previous string, append buffer for new string
 * @return box string including "\n"
 * @retval NULL read() return -1 means error, and malloc fail in strjoin()
 * @retval box read() return 0 means no more data in the file
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

/**
 * @fn *separate_back(char *box)
 * @brief extract backward of string
 * @param[in] box string including "\n"
 * @return substring behind "\n" or NULL in case of no "\n"
 * @retval NULL in case of no "\n", and malloc fail in substr()
 */

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

/**
 * @fn *separate_front(char *box)
 * @brief extract forward of string
 * @param[in] box string read from text including "\n"
 * @return front substring before "\n"
 * @retval NULL malloc fail in substr()
 */

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
 * @brief get string from file and return line until "\n"
 * @param[in]	fd file descriptor
 * @return substring line extracted as the front part
 * @retval NULL read() error, malloc fail cases
 * @attention manage free and NULL
 * @note
 *	- read_file(): make string with p and read()
 *	- separate_back(): extract substring as "p" backward since "\n"
 *	- separate_front(): extract substring as "line" untill "\n"
 */

char	*get_next_line(int fd)
{
	static char	*p;
	char		*str;
	char		*line;

	str = NULL;
	str = read_file(fd, p);
	if (str == NULL)
	{
		if (p != NULL)
			free(p);
		p = NULL;
		return (NULL);
	}
	line = separate_front(str);
	if (line == NULL)
	{
		if (str != NULL)
			free(str);
		str = NULL;
		p = NULL;
		return (NULL);
	}
	p = separate_back(str);
	free(str);
	return (line);
}
