/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:00:36 by athonda           #+#    #+#             */
/*   Updated: 2024/06/11 22:32:34 by athonda          ###   ########.fr       */
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

int	read_file(int fd, char *box)
{
	ssize_t	len;
	ssize_t len_check;
	char	buf[BUFFER_SIZE];

	len = 0;
	len_check = read(fd, buf, 1);
	if (len_check < 0)
		return (-1);
	len = len_check;
	*box = *buf;
	box++;
	while (*buf != '\n')
	{
		len_check = read(fd, buf, 1);
		if (len_check < 0)
			return (-1);
		if (len_check == 0)
			return (0);
		len = len + len_check;
		*box = *buf;
		box++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	p[BUFFER_SIZE];
	ssize_t		len;

	len = read_file(fd, p);
	if (len == -1 || len == 0)
		return (NULL);
	p[len - 1] = '\0';
	return (p);
}

int	main(void)
{
	int	fd;
	char	*p;

	fd = open("./test_open.txt", 0);
	if (fd == -1)
	{
		printf("file open error!\n");
		return (0);
	}
	while ((p = get_next_line(fd)))
	{
		printf("%s\n", p);
	}
	close(fd);
	return (0);
}